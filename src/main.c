/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:56:25 by tapple            #+#    #+#             */
/*   Updated: 2022/01/17 17:13:48 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	open_files(t_pipex *pipex, char **argv, int argc)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		perror_error("does not open argv[1]");
	pipex->outfile = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0000644);
	if (pipex->outfile == -1)
		perror_error("does not open argv[argc - 1]");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		err("incorrect number of arguments");
	open_files(&pipex, argv, argc);
	if (pipe(pipex.fd) == -1)
		perror_error("pipex error");
	pipex.cmd_path = find_path(envp);
	pipex.cmds = ft_split(pipex.cmd_path, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		perror_error("fork error");
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		perror_error("fork error");
	if (pipex.pid2 == 0)
		second_child(pipex, argv, envp);
	close_pipe(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	parent_free(&pipex);
	return (0);
}

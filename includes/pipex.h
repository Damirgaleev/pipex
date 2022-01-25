/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:00:34 by tapple            #+#    #+#             */
/*   Updated: 2022/01/19 16:42:18 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*cmd_path;
	char	**cmds;
	char	**cmd_args;
	char	*comand;
}			t_pipex;

int		main(int argc, char **argv, char **envp);
int		err(char *msg);
void	perror_error(char *msg);
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	close_pipe(t_pipex *pipex);
char	*find_path(char **envp);
char	*get_cmd(char *cmd, char **paths);
void	first_child(t_pipex pipex, char **argv, char **envp);
void	second_child(t_pipex pipex, char **argv, char **envp);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:59:01 by tapple            #+#    #+#             */
/*   Updated: 2022/01/17 16:59:08 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmds[i])
	{
		free(pipex->cmds[i]);
		i++;
	}
	free(pipex->cmds);
}

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->comand);
}

void	close_pipe(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

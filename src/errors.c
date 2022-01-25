/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:58:53 by tapple            #+#    #+#             */
/*   Updated: 2022/01/17 16:58:54 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	err(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return (1);
}

void	perror_error(char *msg)
{
	perror(msg);
	exit(1);
}

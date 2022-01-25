/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:41:46 by tapple            #+#    #+#             */
/*   Updated: 2021/10/09 20:14:55 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	if (dstsize)
	{
		i = 0;
		while (src[i] && (i < dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

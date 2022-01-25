/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:23:23 by tapple            #+#    #+#             */
/*   Updated: 2021/10/24 11:23:24 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == NULL)
		return (NULL);
	while (*s1)
	{
		*(res++) = *(s1++);
		i++;
	}
	while (*s2)
	{
		*(res++) = *(s2++);
		i++;
	}
	*res = '\0';
	return (res - i);
}

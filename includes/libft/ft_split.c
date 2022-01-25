/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:22:10 by tapple            #+#    #+#             */
/*   Updated: 2022/01/15 01:23:55 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

char	*init(char const *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, i + 1);
	return (ptr);
}

char	**memfree(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**str;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		while (s[0] == c)
			s++;
		str[i] = init(s, c);
		if (!(str[i]))
			return (memfree(str));
		s = s + ft_strlen(str[i]);
	}
	str[i] = 0;
	return (str);
}

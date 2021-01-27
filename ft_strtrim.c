/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 23:13:59 by rburton           #+#    #+#             */
/*   Updated: 2020/11/26 13:30:08 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lndx(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	nomatch;

	i = 0;
	j = 0;
	nomatch = 0;
	while (s1[i])
	{
		while (set[j])
		{
			if (s1[i] != set[j])
				nomatch++;
			j++;
		}
		j = 0;
		if (nomatch < ft_strlen(set))
		{
			i++;
			nomatch = 0;
		}
		else
			return (i);
	}
	return (0);
}

static size_t	rndx(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	nomatch;

	i = ft_strlen(s1) - 1;
	j = 0;
	nomatch = 0;
	while (i > 0)
	{
		while (set[j])
		{
			if (s1[i] != set[j])
				nomatch++;
			j++;
		}
		j = 0;
		if (nomatch < ft_strlen(set))
		{
			i--;
			nomatch = 0;
		}
		else
			return (i);
	}
	return (0);
}
/*
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char		*a;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - i;
	while (j && ft_strchr(set, s1[i + j]))
		j--;
	a = ft_substr((char*)s1, i, j + 1);
	return (a);
}
*/
char			*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	strim = (char*)malloc((rndx(s1, set) - lndx(s1, set) + 2) * sizeof(char));
	if (NULL == strim)
		return (NULL);
	i = 0;
	j = lndx(s1, set);
	while (i < (rndx(s1, set) - lndx(s1, set) + 1))
	{
		strim[i] = s1[j];
		i++;
		j++;
	}
	if (lndx(s1, set) == 0 && rndx(s1, set) == 0)
		strim[0] = '\0';
	strim[i] = '\0';
	return (strim);
}

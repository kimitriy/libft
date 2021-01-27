/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 23:13:59 by rburton           #+#    #+#             */
/*   Updated: 2020/10/04 23:14:13 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	wrdn;
	size_t	i;
	size_t	strt;

	if (!s)
		return (NULL);
	i = -1;
	wrdn = 0;
	while (s[++i])
		if ((s[i] == c && (s[i + 1] != c &&
		s[i + 1] != 0)) || (s[i] != c && s[i + 1] == 0))
			wrdn++;
	if (!(arr = (char**)malloc((wrdn + 1) * sizeof(char*))))
		return (NULL);
	i = -1;
	wrdn = 0;
	strt = 0;
	while (s[++i])
		if (s[i] == c && s[i + 1] != c)
			strt = i + 1;
		else if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			arr[wrdn++] = ft_substr(s, strt, i - strt + 1);
	arr[wrdn] = NULL;
	return (arr);
}

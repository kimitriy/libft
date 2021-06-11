/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 23:13:59 by rburton           #+#    #+#             */
/*   Updated: 2020/10/04 23:14:13 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str_n;
	size_t		k;
	size_t		sl;

	if (!s)
		return (0);
	sl = ft_strlen(s);
	if (start >= sl)
		return (ft_strdup(""));
	str_n = (char *)ft_calloc((len + 1), sizeof(char));
	k = 0;
	while (k + start < sl && k < len)
	{
		*(str_n + k) = *(s + start + k);
		k++;
	}
	str_n[k] = '\0';
	return (str_n);
}

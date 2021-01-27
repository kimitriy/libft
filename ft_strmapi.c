/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 23:13:59 by rburton           #+#    #+#             */
/*   Updated: 2020/10/04 23:14:13 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*pstr;

	if (s == NULL)
		return (NULL);
	pstr = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (NULL == pstr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		pstr[i] = f(i, s[i]);
		i++;
	}
	pstr[i] = '\0';
	return (pstr);
}

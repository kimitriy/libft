/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 23:13:59 by rburton           #+#    #+#             */
/*   Updated: 2020/12/01 17:57:15 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlength(long int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i += 1;
	return (i);
}

static void		strreverse(char *str)
{
	size_t	i;
	char	tmp;

	i = 0;
	tmp = 'c';
	while (i < ft_strlen(str) / 2)
	{
		tmp = str[i];
		str[i] = str[ft_strlen(str) - 1 - i];
		str[ft_strlen(str) - 1 - i] = tmp;
		i++;
	}
}

char			*ft_itoa(int n)
{
	size_t		j;
	long int	innern;
	char		*pstr;

	innern = (long int)n;
	pstr = (char*)malloc((strlength(n) + 1) * sizeof(char));
	if (pstr == NULL)
		return (NULL);
	if (n < 0)
		innern = -innern;
	j = 0;
	while (j < strlength(n))
	{
		pstr[j] = (innern % 10) + '0';
		innern = innern / 10;
		j++;
	}
	if (n < 0)
		pstr[j - 1] = '-';
	pstr[j] = '\0';
	strreverse(pstr);
	return (pstr);
}

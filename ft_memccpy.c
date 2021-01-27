/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:13:20 by rburton           #+#    #+#             */
/*   Updated: 2020/10/29 10:13:26 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	symb;

	symb = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char*)src)[i] != symb)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
		else
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			return (&dst[i + 1]);
		}
	}
	return (NULL);
}

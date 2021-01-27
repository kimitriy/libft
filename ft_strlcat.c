/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:13:20 by rburton           #+#    #+#             */
/*   Updated: 2020/10/29 10:13:26 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_init_l;

	dst_init_l = ft_strlen(dst);
	if (dstsize <= dst_init_l)
		return (dstsize + ft_strlen(src));
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (dstsize - dst_init_l - 1) && src[i])
	{
		dst[dst_init_l + i] = src[i];
		i++;
	}
	dst[dst_init_l + i] = '\0';
	return (dst_init_l + ft_strlen(src));
}

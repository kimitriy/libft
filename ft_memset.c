/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:13:20 by rburton           #+#    #+#             */
/*   Updated: 2020/10/29 10:13:26 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	symbol;
	unsigned char	*mem;

	mem = b;
	symbol = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		mem[i] = symbol;
		i++;
	}
	return (b);
}

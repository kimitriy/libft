/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 23:13:59 by rburton           #+#    #+#             */
/*   Updated: 2020/10/04 23:14:13 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstck, const char *ndl, size_t len)
{
	size_t	i;
	char	*return_value;
	char	*inner_hstck;

	i = 0;
	return_value = NULL;
	inner_hstck = (char*)hstck;
	if (ft_strlen(ndl) == 0)
		return (inner_hstck);
	while (inner_hstck[i] && i < len)
	{
		if (ft_strncmp(&inner_hstck[i], ndl, ft_strlen(ndl)) == 0)
		{
			return_value = &inner_hstck[i];
			break ;
		}
		i++;
	}
	if ((i - 1) + ft_strlen(ndl) < len)
		return (return_value);
	else
		return (NULL);
}

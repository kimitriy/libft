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

int	words_counter(const char *str, char dlmtr)
{
	int		wn; //words number
	int		ndf; //non dlmtr flag
	int		i;

	i = 0;
	wn = 0;
	ndf = 0;
	while (str[i])
	{
		if (str[i] != dlmtr && ndf == 0 && str[i + 1] != '\0')
			ndf = 1;
		else if (str[i] != dlmtr && ndf == 0 && str[i + 1] == '\0')
			wn++;
		else if ((str[i] == dlmtr && ndf == 1) || (str[i] != dlmtr && str[i + 1] == '\0'))
		{
			wn++;
			ndf = 0;
		}
		i++;
	}
	return (wn);
}

void	parse_and_write_to_arr(char **arr, const char *str, char dlmtr, int wn)
{
	int				i;
	int				wi; //word indx
	size_t			len; //length number
	unsigned int	strt; //start indx

	i = -1;
	wi = 0;
	strt = 0;
	while (wi < wn && str[++i])
	{
		if (str[i] != dlmtr)
		{
			strt = i;
			len = 0;
			while (str[i] != dlmtr && str[i] != '\0')
			{
				len++;
				i++;
			}	
			arr[wi] = ft_substr(str, strt, len);
			wi++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		wn; //words number

	wn = words_counter(s, c);
	arr = (char **)ft_calloc(wn + 1, sizeof(char *));
	parse_and_write_to_arr(arr, s, c, wn);
	return (arr);
}

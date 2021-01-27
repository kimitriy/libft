/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 23:13:59 by rburton           #+#    #+#             */
/*   Updated: 2020/10/04 23:14:13 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*newlist;
	t_list	*newel;

	if (lst == NULL)
		return (NULL);
	newel = ft_lstnew(f(lst->content));
	if (newel == NULL)
		return (NULL);
	newlist = newel;
	lst = lst->next;
	while (lst)
	{
		newel->next = ft_lstnew(f(lst->content));
		if (newel->next == NULL)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		newel = newel->next;
		lst = lst->next;
	}
	return (newlist);
}

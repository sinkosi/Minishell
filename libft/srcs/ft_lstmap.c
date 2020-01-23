/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:18:47 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/25 16:35:49 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mylist;

	if (lst == NULL)
		return (NULL);
	if (f == NULL)
		return (NULL);
	mylist = f(lst);
	if (mylist == NULL && lst->next == NULL)
		return (NULL);
	else if (mylist != NULL && lst->next != NULL)
		mylist->next = ft_lstmap(lst->next, f);
	return (mylist);
}
/*
** This function performs operations on every element of a list and returns
** a brand new list. It does not link the list or add it to anything. This is
** just fresh data from whatever (*f) may happen to be.
*/

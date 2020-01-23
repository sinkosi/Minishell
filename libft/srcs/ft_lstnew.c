/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:03:30 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/25 14:10:27 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*mylist;

	if (!(mylist = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (content_size < 0)
		return (NULL);
	if (!(mylist->content = (void *)malloc(sizeof(content_size) * 1)))
		return (NULL);
	mylist->next = NULL;
	if (content == NULL)
	{
		mylist->content_size = 0;
		mylist->content = NULL;
	}
	else
	{
		mylist->content_size = content_size;
		ft_memmove(mylist->content, content, content_size);
		mylist->content_size = content_size;
	}
	return (mylist);
}

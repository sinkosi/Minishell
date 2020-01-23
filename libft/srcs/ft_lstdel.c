/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:03:14 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/25 15:52:17 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*mylist;
	t_list	*tmplist;

	tmplist = *alst;
	if (del != NULL)
		while (tmplist != NULL)
		{
			mylist = tmplist->next;
			del(tmplist->content, tmplist->content_size);
			free(tmplist);
			tmplist = mylist;
		}
	*(alst) = NULL;
}

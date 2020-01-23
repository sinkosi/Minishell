/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:43:53 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 13:52:41 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** FT_FLAG_SPACE.c - The purpose of this function is to check if a space has
**		is required. If the number is negative (my_printf->flag_plus == -1),
**		then the function would print a negative number in ft_flag_plus.c.
**		We check that flag_space is set to 1, print the space and update our
**		return value.
*/

void	ft_flag_space(t_printf *my_printf, int fd)
{
	if (my_printf->flag_space == 1 && my_printf->flag_plus == 0)
	{
		ft_putchar_fd(' ', fd);
		my_printf->f_return += 1;
	}
}

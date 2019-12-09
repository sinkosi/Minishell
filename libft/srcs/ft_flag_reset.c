/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 10:39:22 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/16 08:56:10 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_flag_reset(t_printf *my_printf)
{
	my_printf->convert = 0;
	my_printf->flag_minus = 0;
	my_printf->flag_plus = 0;
	my_printf->flag_space = 0;
	my_printf->flag_hash = 0;
	my_printf->flag_zero = 0;
	my_printf->field_width = 0;
	my_printf->prec_width = 0;
	my_printf->h = 0;
	my_printf->l = 0;
	my_printf->lc = 0;
	my_printf->j = 0;
	my_printf->z = 0;
}

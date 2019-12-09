/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:01:04 by sinkosi           #+#    #+#             */
/*   Updated: 2019/07/28 12:01:05 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_error(char *str)
{
	char *err1;
	char *err2;

	err1 = ("\nERROR: FLAG CHECK FAILURE");
	err2 = ("\nERROR: FLAG FAILURE");
	ft_putstr(str);
	exit(-1);
}

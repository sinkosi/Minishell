/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:34:13 by sinkosi           #+#    #+#             */
/*   Updated: 2019/07/09 15:52:20 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	vector_add(t_vector v1, t_vector v2)
{
	t_vector sum;

	sum.x = v1.x + v2.x;
	sum.y = v1.y + v2.y;
	sum.z = v1.z + v2.y;
	return (sum);
}

t_vector	vector_subtract(t_vector v1, t_vector v2)
{
	t_vector sum;

	sum.x = v1.x - v2.x;
	sum.y = v1.y - v2.y;
	sum.z = v1.z - v2.z;
	return (sum);
}

void		vector_multiply(t_vector v1, double multiple)
{
	v1.x = multiple * v1.x;
	v1.y = multiple * v1.y;
	v1.z = multiple * v1.z;
}

void		vector_divide(t_vector v1, double divisor)
{
	v1.x = (v1.x / divisor);
	v1.y = (v1.y / divisor);
	v1.z = (v1.z / divisor);
}

double		vector_magnitude(t_vector v1)
{
	double	magnitude;

	magnitude = ft_power(v1.x, 2) + ft_power(v1.y, 2) + ft_power(v1.z, 2);
	magnitude = ft_sqrt(magnitude);
	return (ft_fabs(magnitude));
}

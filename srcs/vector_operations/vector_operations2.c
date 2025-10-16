/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:55:58 by anony             #+#    #+#             */
/*   Updated: 2025/10/02 21:01:44 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	vec_dot_product(t_coordinates a, t_coordinates b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vec_magnitude(t_coordinates a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

int	vec_equals(t_coordinates a, t_coordinates b)
{
	return (fabs(a.x - b.x) < EPSILON
		&& fabs(a.y - b.y) < EPSILON
		&& fabs(a.z - b.z) < EPSILON);
}

t_coordinates	vec_creat(double x, double y, double z)
{
	t_coordinates	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

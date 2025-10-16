/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:55:29 by mizhouis          #+#    #+#             */
/*   Updated: 2025/10/02 21:01:14 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/**
 * @brief substract b from a (a - b)
 *
 * @param a a point to substract from
 * @param b a vector or point to substract
 * @param c address of stuct c to write the result in
 * @return no return
 */
t_coordinates	vec_substract(t_coordinates a, t_coordinates b)
{
	t_coordinates	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_coordinates	vec_add(t_coordinates a, t_coordinates b)
{
	t_coordinates	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_coordinates	vec_scala_multiply(t_coordinates a, double b)
{
	t_coordinates	c;

	c.x = a.x * b;
	c.y = a.y * b;
	c.z = a.z * b;
	return (c);
}

t_coordinates	vec_scala_divide(t_coordinates a, double b)
{
	t_coordinates	c;

	if (fabs(b) < EPSILON)
	{
		error_msg(ERROR_DIVISION_ZERO);
		exit(1);
	}
	c.x = a.x / b;
	c.y = a.y / b;
	c.z = a.z / b;
	return (c);
}

t_coordinates	vec_normalize(t_coordinates a)
{
	t_coordinates	c;
	double			magnitude;

	magnitude = vec_magnitude(a);
	if (fabs(magnitude) < EPSILON)
	{
		error_msg(ERROR_DIVISION_ZERO);
		exit(1);
	}
	c.x = a.x / magnitude;
	c.y = a.y / magnitude;
	c.z = a.z / magnitude;
	return (c);
}

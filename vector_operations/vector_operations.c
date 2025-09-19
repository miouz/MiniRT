/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizhouis <mizhouis@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:55:29 by mizhouis          #+#    #+#             */
/*   Updated: 2025/09/17 19:55:29 by mizhouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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
	c.type = a.type - b.type;
	return (c);
}

t_coordinates	vec_add(t_coordinates a, t_coordinates b)
{
	t_coordinates	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	c.type = a.type + b.type;
	return (c);
}

t_coordinates	vec_sclala_multiply(t_coordinates a, double b)
{
	t_coordinates	c;

	c.x = a.x * b;
	c.y = a.y * b;
	c.z = a.z * b;
	c.type = a.type * b;
	return (c);
}

t_coordinates	vec_scala_divide(t_coordinates a, double b)
{
	t_coordinates	c;

	c.x = a.x / b;
	c.y = a.y / b;
	c.z = a.z / b;
	c.type = a.type / b;
	return (c);
}


t_coordinates	vec_normalize(t_coordinates a)
{
	t_coordinates	c;
	double			magnitude;

	magnitude = vec_magnitude(a);
	c.x = a.x / magnitude;
	c.y = a.y / magnitude;
	c.z = a.z / magnitude;
	c.type = a.type / magnitude;
	return (c);
}

double	vec_dot_product(t_coordinates a, t_coordinates b)
{
	if (a.c > 0 || b.c > 0)
		error_msg(ERROR_VEC_TYPE);
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vec_magnitude(t_coordinates a)
{
	if (a.c > 0 || b.c > 0)
		error_msg(ERROR_VEC_TYPE);
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

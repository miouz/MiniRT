/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:23:40 by mzhou             #+#    #+#             */
/*   Updated: 2025/10/01 17:18:30 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/**
 * @brief get ray-sphere intersect time value
 *
 * @param a double a
 * @param b double b
 * @param discriminant double discriminant
 * @return the smallest positive or zero value time 
 * 			or TIME_VAL_NO_INTERSECTION -1;
 */
double	get_time_from_discriminant(double a, double b, double discriminant)
{
	double	t1;
	double	t2;

	if (discriminant < 0)
		return (TIME_VAL_NO_INTERSECTION);
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	t2 = (-b + sqrt(discriminant)) / (2 * a);
	if (t1 >= 0)
	{
		if (t2 >= 0 && t2 < t1)
			t1 = t2;
		return (t1);
	}
	else if (t1 < 0 && t2 >= 0)
		return (t2);
	return (TIME_VAL_NO_INTERSECTION);
}

/**
 * @brief get the ray's time value if it intersect a sphere
 *  at² + bt + c = 0 where:
 *	D = vector ray.direction, V = vector ray origin to sphere center.
 *	a = D·D
 *	b = 2*(D·V) = 2*dot(direction, origin - center)
 *	c = V·V - r² = dot(origin - center, origin - center) - r²
 * t = (-b ± √(b² - 4ac))/2a where discriminant = b² - 4ac
 * @param object address of the sphere.
 * @param ray address of the given ray.
 * @return time value if intersect, TIME_VAL_NO_INTERSECTION(-1) if no intersection. 
 */
double	get_ray_sphere_intersect_time(t_sphere *sphere, t_ray *ray)
{
	t_coordinates	vec_oc;
	double			a;
	double			b;
	double			c;
	double			discriminant;

	vec_oc = vec_substract(ray->origin, sphere->center);
	a = vec_dot_product(ray->direction, ray->direction);
	// if (fabs(a - 1) > EPSILON)
	// 	error_msg("vector not normalized\n");
	b = 2 * vec_dot_product(ray->direction, vec_oc);
	c = vec_dot_product(vec_oc, vec_oc) - pow(sphere->diameter / 2, 2);
	discriminant = b * b - 4 * a * c;
	return (get_time_from_discriminant(a, b, discriminant));
}

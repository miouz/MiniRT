/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_intersect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:48:58 by mzhou             #+#    #+#             */
/*   Updated: 2025/09/24 15:48:58 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "intersection.h"
#include "../vector_operations/vector_operations.h"

/**
 * @brief check if intersection is in the cylinder's heigh range
 *
 * axis_projection = (P - cylinder.center)·Vc
 * 	where P = ray.origin + tD
 * if -h / 2 <=axis_projection <= h / 2
 * 	then is in range
 *
 * @param cylinder address of cylinder struct
 * @param time time value
 * @return return true or false
 */
static bool	is_within_cylinder_height(t_ray *ray, t_cylinder *cylinder, double time)
{

	double	axis_projection;
	t_coordinates	p;

	convert_ray_time_to_point(ray, time, &p);
	axis_projection = vec_dot_product(vec_substract(p, cylinder->center), cylinder->axis_vector);
	if (axis_projection > cylinder->height / 2 || axis_projection < - cylinder->height / 2)
		return (false);
	return (true);
}

/**
 * @brief check if time is >= 0 and if is <= cylinder's radius
 *
 * @param ray address to ray struct
 * @param cylinder address to cylinder struct
 * @param cap address to cap struct(plane)
 * @param time address to time value
 * @return return true or false
 */
bool	is_valid_time_and_on_caps(t_ray *ray, t_cylinder *cylinder, t_plane *cap, double *time)
{
	t_coordinates	p;

	if (*time < 0)
		return (false);
	convert_ray_time_to_point(ray, *time, &p);
	if (vec_magnitude(vec_substract(p, cap->point)) <= cylinder->diameter / 2)
		return (true);
	return (false);
}

/**
 * @brief get ray-cylinder's top and bas caps' intersection time
 *
 * get ray-plane intersect time firstly
 * then check if the point is in the caps circle range
 *
 * @param ray address to struct ray
 * @param cylinder address to struct cylinder
 * @param time address of time to reference
 */
static void	get_ray_cylinder_caps_intersect_time(t_ray *ray, t_cylinder *cylinder, double *time)
{
	t_plane	top;
	t_plane	bottom;
	double	top_time;
	double	bottom_time;

	top.point = vec_add(cylinder->center,
					  vec_scala_multiply(cylinder->axis_vector, cylinder->height / 2));
	top.ortho_vector = cylinder->axis_vector;
	bottom.point = vec_substract(cylinder->center,
					  vec_scala_multiply(cylinder->axis_vector, cylinder->height / 2));
	bottom.ortho_vector = cylinder->axis_vector;
	top_time = get_ray_plane_intersect_time(&top, ray);
	bottom_time = get_ray_plane_intersect_time(&bottom, ray);
	if (is_valid_time_and_on_caps(ray, cylinder, &top, &top_time) == true
		&& (*time == TIME_VAL_NO_INTERSECTION || top_time < *time))
		*time = top_time;
	if (is_valid_time_and_on_caps(ray, cylinder, &bottom, &bottom_time) == true
		&& (*time == TIME_VAL_NO_INTERSECTION || bottom_time < *time))
		*time = bottom_time;
}

/**
 * @brief calculate a given ray and a cylinder's intersection time
 *
 *  at² + bt + c = 0 where:
 *	D = vector ray.direction, V = vector from cylinder center to ray origin.
 *	Vc = cylinder axis vector
 *	a = D·D - (D·Vc)²
 *	b = 2*(V·D - (V·Vc)(D·Vc))
 *	c = V·V - (V·Vc)²  - r²
 * t = (-b ± √(b² - 4ac))/2a where discriminant = b² - 4ac
 * then calculate the intersection of ray-cylinder_base and ray-cylinder_top
 *
 * @param cylinder address of cylinder struct
 * @param ray address of ray struct
 * @return the double time value or TIME_VAL_NO_INTERSECT(-1)
 */
double	get_ray_cylinder_intersect_time(t_cylinder *cylinder, t_ray *ray)
{
	t_coordinates	vec_oc;
	double			a;
	double			b;
	double			c;
	double 			time;

	vec_oc = vec_substract(ray->origin, cylinder->center);
	a = vec_dot_product(ray->direction, ray->direction)
		- pow(vec_dot_product(ray->direction, cylinder->axis_vector), 2);
	if (fabs(a) >= EPSILON)
	{
		b = 2 * (vec_dot_product(vec_oc, ray->direction)
			- vec_dot_product(vec_oc, cylinder->axis_vector)
			* vec_dot_product(ray->direction, cylinder->axis_vector));
		c = vec_dot_product(vec_oc, vec_oc)
			- pow(vec_dot_product(vec_oc, cylinder->axis_vector ), 2)
			- pow(cylinder->diameter / 2, 2);
		time = get_time_from_discriminant(a, b,  b * b - 4 * a * c);
		if (is_within_cylinder_height(ray, cylinder, time) == false)
			time = TIME_VAL_NO_INTERSECTION;
	}
	get_ray_cylinder_caps_intersect_time(ray, cylinder, &time);
	return (time);
}

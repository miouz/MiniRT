/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane_intersect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:56:05 by mzhou             #+#    #+#             */
/*   Updated: 2025/09/24 11:57:46 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	check_ray_is_in_plane(t_plane *plane, t_ray *ray, double d)
{
	if (vec_dot_product(plane->ortho_vector, ray->origin) + d == 0)
		return (true);
	else
	 	return (false);
}

/**
 * @brief calculate the time value of ray-plane intersection
 * N · P + d = 0 where 
 * 	N is plane.ortho_vector
 * 	P is a point on plane 
 * 	d = N · P0 where P0 is plane.point
 * t = -(N · O + d) / D · N where
 * 	O is ray.origin
 * 	D is ray.direction
 * 	denominator = D · N
 *
 * @param plane address of structure plane
 * @param ray address of structure ray
 * @return time_value in double
 */
double	get_ray_plane_intersect_time(t_plane *plane, t_ray *ray)
{
	double	denominator;
	double	d;
	double	t;

	denominator = vec_dot_product(ray->direction, plane->ortho_vector);
	d = - vec_dot_product(plane->ortho_vector, plane->point);
	//if its parallele and ray is int the plane
	if (fabs(denominator) < EPSILON && check_ray_is_in_plane(plane, ray, d) == true)
		return (t = 0);
	t = -(vec_dot_product(plane->ortho_vector, ray->origin) + d) / denominator;
	if (t >= 0)
		return (t);
	else
		return (TIME_VAL_NO_INTERSECTION);
}

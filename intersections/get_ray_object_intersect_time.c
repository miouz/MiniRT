/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_object_intersect_time.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:23:40 by mzhou             #+#    #+#             */
/*   Updated: 2025/09/22 15:23:45 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	get_ray_plane_intersect_time(t_plane *plane, t_ray *ray);
{

}
/**
 * @brief get the ray's time value if it intersect a sphere
 *
 * @param object address of the sphere.
 * @param ray address of the given ray.
 * @return time value if intersect, TIME_VAL_NO_INTERSECTION(-1) if no intersection. 
 */
double	get_ray_sphere_intersect_time(t_sphere *sphere, t_ray *ray)
{
	double			len;
	t_coordinates	vec_sphere_to_ray;
	double			sphere_to_ray_perpendicular;

	vec_sphere_to_ray = vec_substract(sphere->center, ray->origin);
	len = vec_dot_product(sphere_to_ray, ray->direction);
	//no intersection with this sphyere
	if (len < 0)
		return (TIME_VAL_NO_INTERSECTION);
	sphere_to_ray_perpendicular = sqrt(pow(vec_magnitude(sphere_to_ray), 2) - len * len);
	if (sphere_to_ray_perpendicular < 0)
		return (TIME_VAL_NO_INTERSECTION);
	if (sphere_to_ray_perpendicular > object->diameter)
		return (TIME_VAL_NO_INTERSECTION);
	return (len - sqrt(pow(object->diameter, 2) - pow(sphere_to_ray_perpendicular, 2)));
}

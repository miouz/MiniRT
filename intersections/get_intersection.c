/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:57:24 by mzhou             #+#    #+#             */
/*   Updated: 2025/09/16 15:57:24 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <math.h>
#include <stdlib.h>

int	get_sphere_intersect_point(t_object *object, t_ray *ray, t_intersect *intersect_point)
{
	double			l;
	double			new_t;
	t_coordinates	sphere_to_ray;
	double			sphere_to_ray_perpendicular;

	vec_substract(object->center, ray->origin, &sphere_to_ray);
	l = vec_dot_product(sphere_to_ray, ray->direction);
	//no intersection with this sphyere
	if (l < 0)
		return (intersect_point->t = -1, EXIT_FAILURE);
	sphere_to_ray_perpendicular = sqrt(pow(vec_magnitude(sphere_to_ray), 2) - l * l);
	if (sphere_to_ray_perpendicular < 0)
		return (intersect_point->t = -1, EXIT_FAILURE);
	if (sphere_to_ray_perpendicular > object->diameter)
		return (intersect_point->t = -1, EXIT_SUCCESS);
	new_t = l - sqrt(pow(object->diameter, 2) - pow(sphere_to_ray_perpendicular, 2));
	if (intersect_point->t == -1 || intersect_point->t >= 0 && new_t < intersect_point->t)
		intersect_point->t = new_t;
	return (EXIT_SUCCESS);
}

/**
 * @brief get one the given object's closest_intersect_point to a given ray.
 *
 * @param ray address of the given ray struct.
 * @param object address of the given object struct.
 * @param intersect_point address of the intersect_point to fill.
 * @return EXIT_SUCCESS or EXIT_FAILURE.
 */
int	get_object_closest_intersect_point(t_ray *ray, t_object *object,
										t_intersect *intersect_point)
{
	if (object->type == SPHERE)
		return (get_sphere_intersect_point(object, ray, intersect_point));
	// if (object->type == PLANE)
	// 	return (get_plane_intersect_point(object, ray, intersect_point));
	// if (object->type == CYLINDER)
	// 	return (get_cylinder_intersect_point(object, ray, intersect_point));
	//no tyoe corrresponds
	return (EXIT_FAILURE);
}

/**
 * @brief calcul the hit point of the given ray
 *
 * @param intersect_point address of one intersect_point to fill.
 * @param ray the given ray to calculate for.
 * @param scene the scene composed by an array of object.
 * @return EXIT_SUCCESS or EXIT_FAILURE.
 */
int	get_hit_point(t_intersect *intersect_point, t_ray *ray,
							t_object *scene)
{
	int			object_index;

	object_index = 0;
	while (object_index < SCENE_OBJECT_QUANTITIES)
	{
		get_object_closest_intersect_point(ray, &scene[object_index], intersect_point);
		object_index++;
	}
	return (EXIT_SUCCESS);
}

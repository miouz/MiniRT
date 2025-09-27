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
#include "intersection.h"
#include "../vector_operations/vector_operations.h"
#include <math.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	error_msg(char *msg)
{
	int	size;

	size = ft_strlen(msg);
	write(2, msg, size);
}

void	convert_ray_time_to_point(t_ray *ray, double time, t_coordinates *point)
{
	*point = vec_add(ray->origin, vec_scala_multiply(ray->direction, time));
}

/**
 * @brief get the given ray's smallest time value of intersection point.
 *
 * @param ray address of the given ray struct.
 * @param object address of the given object struct.
 * @param time address of the time to reference.
 * @return EXIT_SUCCESS or EXIT_FAILURE.
 */
int	get_object_smallest_intersect_time(t_ray *ray, t_object *object,
										double *time, t_intersect *intersect_point)
{
	double	new_time;

	if (object->type == SPHERE)
		new_time = get_ray_sphere_intersect_time(&object->data.sphere, ray);
	else if (object->type == PLANE)
		new_time = get_ray_plane_intersect_time(&object->data.plane, ray);
	else if (object->type == CYLINDER)
		new_time = get_ray_cylinder_intersect_time(&object->data.cylinder, ray);
	if (new_time >= 0 && (*time == TIME_VAL_NO_INTERSECTION || new_time < *time))
	{
		*time = new_time;
		intersect_point->obj = object;
	}
	return (EXIT_SUCCESS);
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
	int		object_index;
	double	time;

	object_index = 0;
	time = TIME_VAL_NO_INTERSECTION;
	intersect_point->obj = NULL;
	while (object_index < SCENE_OBJECT_QUANTITIES)
	{
		get_object_smallest_intersect_time(ray, &scene[object_index], &time, intersect_point);
		object_index++;
	}
	//if there is hit point
	if (time >= 0)
		convert_ray_time_to_point(ray, time, &intersect_point->point);
	return (EXIT_SUCCESS);
}

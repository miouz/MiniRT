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

/**
 * @brief get the given ray's smallest time value of intersection point.
 *
 * @param ray address of the given ray struct.
 * @param object address of the given object struct.
 * @param time address of the time to reference.
 * @return EXIT_SUCCESS or EXIT_FAILURE.
 */
int	get_object_smallest_intersect_time(t_ray *ray, t_object *object,
										double *time)
{
	double	new_time;

	if (object->type == SPHERE)
		new_time = get_ray_sphere_intersect_time(&object->data.sphere, ray);
	// else if (object->type == PLANE)
	// 	new_time = get_plane_intersect_point(object, ray);
	// else if (object->type == CYLINDER)
	// 	new_time = get_cylinder_intersect_point(object, ray, intersect_point);
	//no tyoe corrresponds
	if (*time == TIME_VAL_NO_INTERSECTION || *time >= 0 && new_time < *time)
		*time = new_time;
	return (EXIT_SUCCESS);
}

void	convert_ray_time_to_point(t_ray *ray, double time, t_intersect *intersect_point)
{
	*intersect_point->intersect = vec_add(ray->origin, vec_scala_multiply(ray->direction, time));
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
	double	time[SCENE_OBJECT_QUANTITIES];

	object_index = 0;
	while (object_index < SCENE_OBJECT_QUANTITIES)
	{
		time[object_index] = TIME_VAL_NO_INTERSECTION;
		get_object_smallest_intersect_time(ray, &scene[object_index], &time[object_index]);
		//if there is hit point
		if (time[object_index] >= 0)
		{
			convert_ray_time_to_point(ray, time[object_index], intersect_point);
			intersect_point->obj = &scene[object_index];
		}
		//if no hit point
		else
			intersect_point->obj = NULL;
		object_index++;
	}
	return (EXIT_SUCCESS);
}

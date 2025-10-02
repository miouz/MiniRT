/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:57:24 by mzhou             #+#    #+#             */
/*   Updated: 2025/10/02 20:40:06 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	convert_ray_time_to_point(t_ray *ray, double time,
			t_coordinates *point)
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
	double	new_t;

	if (object->type == SPHERE)
		new_t = get_ray_sphere_inter_time(&object->data.sphere, ray);
	else if (object->type == PLANE)
		new_t = get_ray_plane_inter_time(&object->data.plane, ray);
	else if (object->type == CYLINDER)
		new_t = get_ray_cylinder_inter_time(&object->data.cylinder, ray);
	else
		return (exit(1), EXIT_FAILURE);
	if (new_t >= 0 && (*time == TIME_VAL_NO_INTERSECTION || new_t < *time))
	{
		*time = new_t;
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
							t_object *scene, int nb_objects)
{
	int		object_index;
	double	time;

	object_index = 0;
	time = TIME_VAL_NO_INTERSECTION;
	intersect_point->obj = NULL;
	while (object_index < nb_objects)
	{
		get_object_smallest_intersect_time(ray, &scene[object_index], &time,
			intersect_point);
		object_index++;
	}
	if (time >= 0)
		convert_ray_time_to_point(ray, time, &intersect_point->point);
	return (EXIT_SUCCESS);
}

void	get_ray_from_camera(t_data *data, int ind, t_ray *ray)
{
	ray->origin = data->camera.center;
	ray->direction.type = 0;
	ray->direction.x = data->pixels[ind].x - ray->origin.x;
	ray->direction.y = data->pixels[ind].y - ray->origin.y;
	ray->direction.z = data->pixels[ind].z - ray->origin.z;
}

void	get_intersects(t_data *data)
{
	int		i;
	int		nb_pixels;
	t_ray	ray;

	i = 0;
	nb_pixels = HEIGHT * LENGHT;
	while (i < nb_pixels)
	{
		get_ray_from_camera(data, i, &ray);
		get_hit_point(&data->intersects[i], &ray, data->objects,
			data->nb_objects);
		i++;
	}
}

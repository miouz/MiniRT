/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:20:58 by anony             #+#    #+#             */
/*   Updated: 2025/10/02 19:30:38 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_boolean	is_enlightened(t_data *data, t_ray *ray)
{
	int		i;
	double	time;

	i = 0;
	while (i < data->nb_objects)
	{
		if (data->objects[i].type == PLANE)
			time = get_ray_plane_inter_time(&data->objects[i].data.plane, ray);
		if (data->objects[i].type == SPHERE)
			time = get_ray_sphere_inter_time(&data->objects[i].data.sphere,
					ray);
		if (data->objects[i].type == CYLINDER)
			time = get_ray_cylinder_inter_time(&data->objects[i].data.cylinder,
					ray);
		if (time >= 0.0 && time < 1.0 - EPSILON)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	fill_light_ray(t_data *data, int ind, t_ray *ray)
{
	ray->direction.x = data->intersects[ind].point.x - data->light.source.x;
	ray->direction.y = data->intersects[ind].point.y - data->light.source.y;
	ray->direction.z = data->intersects[ind].point.z - data->light.source.z;
	ray->origin = data->light.source;
}

t_color	no_intersect_color(t_data *data)
{
	t_color	color;

	color.blue = (int)(data->ambient_lighting.color.blue
			* data->ambient_lighting.intensity);
	color.green = (int)(data->ambient_lighting.color.green
			* data->ambient_lighting.intensity);
	color.red = (int)(data->ambient_lighting.color.red
			* data->ambient_lighting.intensity);
	return (color);
}

t_color	get_pixel_color(t_data *data, int x, int y)
{
	t_ray			light_ray;
	t_coordinates	ortho_vector;
	t_color			col;
	double			in;

	if (!data->intersects[y * LENGHT + x].obj)
		return (no_intersect_color(data));
	fill_light_ray(data, y * LENGHT + x, &light_ray);
	if (is_enlightened(data, &light_ray))
	{
		ortho_vector = get_ortho_vector(data->intersects[y * LENGHT + x]);
		in = data->ambient_lighting.intensity
			- vec_dot_product(ortho_vector, light_ray.direction)
			* data->light.intensity / vec_magnitude(light_ray.direction);
	}
	else
		in = data->ambient_lighting.intensity;
	if (in > 1.0)
		in = 1.0;
	col.red = (int)(in * data->intersects[y * LENGHT + x].obj->color.red);
	col.green = (int)(in * data->intersects[y * LENGHT + x].obj->color.green);
	col.blue = (int)(in * data->intersects[y * LENGHT + x].obj->color.blue);
	return (col);
}

void	get_colors(t_data *data, int size_line)
{
	int		x;
	int		y;
	int		offset;
	t_color	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < LENGHT)
		{
			offset = y * size_line + x * 4;
			color = get_pixel_color(data, x, y);
			data->minilibx.colors[offset] = (char)color.blue;
			data->minilibx.colors[offset + 1] = (char)color.green;
			data->minilibx.colors[offset + 2] = (char)color.red;
			x++;
		}
	y++;
	}
}

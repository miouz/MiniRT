/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:38:44 by anony             #+#    #+#             */
/*   Updated: 2025/10/20 13:19:30 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int	init_pixel_intersects(t_data *data)
{
	data->pixels = malloc((HEIGHT * LENGHT) * sizeof(t_coordinates));
	if (data->pixels == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	data->intersects = malloc((HEIGHT * LENGHT) * sizeof(t_intersect));
	if (data->intersects == NULL)
	{
		perror("malloc");
		free(data->pixels);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	print_parsing(t_data *data)
{
	printf("ambient_light:\n");
	printf("intensity: %f\n", data->ambient_lighting.intensity);
	printf("color is :%d, %d, %d\n", data->ambient_lighting.color.red, data->ambient_lighting.color.green, data->ambient_lighting.color.blue);
	printf("--------------------------\n");

	printf("camara :\n");
	printf("camera center is: %f, %f, %f\n", data->camera.center.x, data->camera.center.y, data->camera.center.z);
	printf("camera vector is: %f, %f, %f\n", data->camera.direction.x, data->camera.direction.y, data->camera.direction.z);
	printf("camera fov is: %d\n", data->camera.fov);
	printf("--------------------------\n");

	if (data->one_spot_light)
	{
	printf("spot_light:\n");
	printf("light center is: %f, %f, %f\n", data->light.source.x, data->light.source.y, data->light.source.z);
	printf("intensity: %f\n", data->light.intensity);
	printf("--------------------------\n");
	}
	
	int obj_index = 0;
	while (obj_index < data->nb_objects)
	{
		if (data->objects[obj_index].type == SPHERE)
		{
			printf("SPHERE:\n");
			printf("sphere center is: %f, %f, %f\n", data->objects[obj_index].data.sphere.center.x, data->objects[obj_index].data.sphere.center.y, data->objects[obj_index].data.sphere.center.z);
			printf("sphere diameter is: %f\n", data->objects[obj_index].data.sphere.diameter);
			printf("color is :%d, %d, %d\n", data->objects[obj_index].color.red, data->objects[obj_index].color.green, data->objects[obj_index].color.blue);
			printf("--------------------------\n");
		}

		if (data->objects[obj_index].type == CYLINDER)
		{
			printf("CYLINDER:\n");
			printf("cylinder center is: %f, %f, %f\n", data->objects[obj_index].data.cylinder.center.x, data->objects[obj_index].data.cylinder.center.y, data->objects[obj_index].data.cylinder.center.z);
			printf("cylinder vector is: %f, %f, %f\n", data->objects[obj_index].data.cylinder.axis_vector.x, data->objects[obj_index].data.cylinder.axis_vector.y, data->objects[obj_index].data.cylinder.axis_vector.z);
			printf("cylinder diameter is: %f\n", data->objects[obj_index].data.cylinder.diameter);
			printf("cylinder height is: %f\n", data->objects[obj_index].data.cylinder.height);
			printf("color is :%d, %d, %d\n", data->objects[obj_index].color.red, data->objects[obj_index].color.green, data->objects[obj_index].color.blue);
			printf("--------------------------\n");
		}
		if (data->objects[obj_index].type == PLANE)
		{
			printf("PLANE:\n");
			printf("plane center is: %f, %f, %f\n", data->objects[obj_index].data.plane.point.x, data->objects[obj_index].data.plane.point.y, data->objects[obj_index].data.plane.point.z);
			printf("plane vector is: %f, %f, %f\n", data->objects[obj_index].data.plane.ortho_vector.x, data->objects[obj_index].data.plane.ortho_vector.y, data->objects[obj_index].data.plane.ortho_vector.z);
			printf("color is :%d, %d, %d\n", data->objects[obj_index].color.red, data->objects[obj_index].color.green, data->objects[obj_index].color.blue);
			printf("--------------------------\n");
		}
		obj_index++;
	}
	return (0);
}

int	free_data_and_exit(t_data *data)
{
	mlx_destroy_image(data->minilibx.mlx_p, data->minilibx.img_p);
	mlx_destroy_window(data->minilibx.mlx_p, data->minilibx.win_p);
	mlx_destroy_display(data->minilibx.mlx_p);
	free(data->minilibx.mlx_p);
	free(data->intersects);
	free(data->pixels);
	free(data->objects);
	data->intersects = NULL;
	data->pixels = NULL;
	data->objects = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

int	keyboard_event(int keycode, t_data *data)
{
	if (keycode == 0xff1b)
		free_data_and_exit(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	setup_data(&data, argc, argv);
	print_parsing(&data);
	init_pixel_intersects(&data);
	initialize_minilibx(&data.minilibx);
	get_pixels_coordinates(&data);
	get_intersects(&data);
	get_colors(&data, data.minilibx.line);
	mlx_put_image_to_window(data.minilibx.mlx_p, data.minilibx.win_p,
		data.minilibx.img_p, 0, 0);
	mlx_hook(data.minilibx.win_p, 17, 0, &free_data_and_exit, &data);
	mlx_hook(data.minilibx.win_p, 2, 1L << 0, &keyboard_event, &data);
	mlx_loop(data.minilibx.mlx_p);
	return (EXIT_SUCCESS);
}

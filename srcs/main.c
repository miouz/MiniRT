/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:38:44 by anony             #+#    #+#             */
/*   Updated: 2025/10/20 16:40:52 by anony            ###   ########.fr       */
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

int	free_data_and_exit_empty(t_data *data)
{
	mlx_destroy_image(data->minilibx.mlx_p, data->minilibx.img_p);
	mlx_destroy_window(data->minilibx.mlx_p, data->minilibx.win_p);
	mlx_destroy_display(data->minilibx.mlx_p);
	free(data->minilibx.mlx_p);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keyboard_event(int keycode, t_data *data)
{
	if (keycode == 0xff1b)
		free_data_and_exit_empty(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc ==1)
	{
	initialize_minilibx(&data.minilibx);
	mlx_put_image_to_window(data.minilibx.mlx_p, data.minilibx.win_p,
		data.minilibx.img_p, 0, 0);
	mlx_hook(data.minilibx.win_p, 17, 0, &free_data_and_exit_empty, &data);
	mlx_hook(data.minilibx.win_p, 2, 1L << 0, &keyboard_event, &data);
	mlx_loop(data.minilibx.mlx_p);
	}
	setup_data(&data, argc, argv);
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

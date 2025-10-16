/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:38:44 by anony             #+#    #+#             */
/*   Updated: 2025/10/02 19:11:42 by anony            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;

	setup_data(&data, argc, argv);
	init_pixel_intersects(&data);
	initialize_minilibx(&data.minilibx);
	get_pixels_coordinates(&data);
	get_intersects(&data);
	get_colors(&data, data.minilibx.line);
	mlx_put_image_to_window(data.minilibx.mlx_p, data.minilibx.win_p,
		data.minilibx.img_p, 0, 0);
	mlx_loop(data.minilibx.mlx_p);
    // clean(data);
	return (0);
}

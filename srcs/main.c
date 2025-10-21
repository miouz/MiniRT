/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:38:44 by anony             #+#    #+#             */
/*   Updated: 2025/10/20 16:50:36 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		display_empty_window(&data);
	else
	{
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
	}
	return (EXIT_SUCCESS);
}

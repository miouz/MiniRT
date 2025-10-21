/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_empty_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:43:35 by mzhou             #+#    #+#             */
/*   Updated: 2025/10/21 13:43:35 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	free_data_and_exit_empty(t_data *data)
{
	close_minilibx(&data->minilibx);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	keyboard_event_empty(int keycode, t_data *data)
{
	if (keycode == 0xff1b)
		free_data_and_exit_empty(data);
	return (0);
}

void	display_empty_window(t_data *data)
{
	initialize_minilibx(&data->minilibx);
	mlx_put_image_to_window(data->minilibx.mlx_p, data->minilibx.win_p,
		data->minilibx.img_p, 0, 0);
	mlx_hook(data->minilibx.win_p, 17, 0, &free_data_and_exit_empty, data);
	mlx_hook(data->minilibx.win_p, 2, 1L << 0, &keyboard_event_empty, data);
	mlx_loop(data->minilibx.mlx_p);
}

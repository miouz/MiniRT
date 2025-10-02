/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:09:25 by anony             #+#    #+#             */
/*   Updated: 2025/10/02 20:53:21 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	close_minilibx(t_minilibx_data *data)
{
	if (data->img_p)
		mlx_destroy_image(data->mlx_p, data->img_p);
	if (data->win_p)
		mlx_destroy_window(data->mlx_p, data->win_p);
	if (data->mlx_p)
		mlx_destroy_display(data->mlx_p);
	if (data->mlx_p)
		free(data->mlx_p);
	exit(0);
}

void	initialize_minilibx(t_minilibx_data *minilibx)
{
	minilibx->mlx_p = mlx_init();
	if (minilibx->mlx_p == NULL)
		return (exit(1));
	minilibx->win_p = mlx_new_window(minilibx->mlx_p, LENGHT,
			HEIGHT, "OMG la classe");
	if (minilibx->win_p == NULL)
	{
		mlx_destroy_display(minilibx->mlx_p);
		return (free(minilibx->mlx_p), exit(1));
	}
	minilibx->img_p = mlx_new_image(minilibx->mlx_p, LENGHT, HEIGHT);
	if (minilibx->img_p == NULL)
	{
		mlx_destroy_window(minilibx->mlx_p, minilibx->win_p);
		mlx_destroy_display(minilibx->mlx_p);
		return (free(minilibx->mlx_p), exit(1));
	}
	minilibx->colors = mlx_get_data_addr(minilibx->img_p, &minilibx->bpp,
			&minilibx->line, &minilibx->end);
	if (minilibx->colors == NULL)
		close_minilibx(minilibx);
}

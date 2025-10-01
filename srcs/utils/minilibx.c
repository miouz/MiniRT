/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:09:25 by anony             #+#    #+#             */
/*   Updated: 2025/10/01 17:40:41 by anony            ###   ########.fr       */
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

void	initialize_minilibx(t_data *data)
{
	data->minilibx->mlx_p = mlx_init();
	if (data->minilibx->mlx_p == NULL)
		return (exit(1));
	data->minilibx->win_p = mlx_new_window(data->minilibx->mlx_p, LENGHT, HEIGHT, "OMG la classe");
	if (data->minilibx->win_p == NULL)
	{
		mlx_destroy_display(data->minilibx->mlx_p);
		return (free(data->minilibx->mlx_p), exit(1));
	}
	data->minilibx->img_p = mlx_new_image(data->minilibx->mlx_p, LENGHT, HEIGHT);
	if (data->minilibx->img_p == NULL)
	{
		mlx_destroy_window(data->minilibx->mlx_p, data->minilibx->win_p);
		mlx_destroy_display(data->minilibx->mlx_p);
		return (free(data->minilibx->mlx_p), exit(1));
	}
	data->colors = mlx_get_data_addr(data->minilibx->img_p, &data->minilibx->bpp, &data->minilibx->line, &data->minilibx->end);
	if (data->colors == NULL)
		close_minilibx(data->minilibx);
}

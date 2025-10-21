/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:33:08 by anony             #+#    #+#             */
/*   Updated: 2025/10/02 20:52:16 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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
	close_minilibx(&data->minilibx);
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

int	ft_strlen(char *str)
{
	int	i;

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

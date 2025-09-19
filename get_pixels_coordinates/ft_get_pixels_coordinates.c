/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixels_coordinates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:10:42 by anony             #+#    #+#             */
/*   Updated: 2025/09/19 13:24:58 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coordinates	ft_get_first_pixel(t_screen scr)
{
	t_coordinates	pixel;
	double	u_offset;
	double	v_offset;

	if (LENGHT % 2 == 0)
		u_offset = -1.0 * ((double)LENGHT / 2.0 - 0.5);
	else
		u_offset = -1.0 * ((double)LENGHT / 2.0);
	if (HEIGHT % 2 == 0)
		v_offset = (double)HEIGHT / 2.0 - 0.5;
	else
		v_offset = (double)HEIGHT / 2.0;
	pixel.x = scr.center.x + u_offset * scr.u.x + v_offset * scr.v.x;
	pixel.y = scr.center.y + u_offset * scr.u.y + v_offset * scr.v.y;
	pixel.z = scr.center.z + u_offset * scr.u.z + v_offset * scr.v.z;
	return (pixel);
}

t_coordinates	ft_get_pixel(int id, t_screen screen, t_coordinates first_pixel)
{
	t_coordinates	pixel;
	int		u_offset;
	int		v_offset;

    if (id == 1)
        return (first_pixel);
	u_offset = (id - 1) % LENGHT;
	v_offset = -1 * (id - 1) / LENGHT;
	pixel.x = first_pixel.x + (double)u_offset * screen.u.x;
    pixel.x += (double)v_offset * screen.v.x;
	pixel.y = first_pixel.y + (double)u_offset * screen.u.y;
    pixel.y += (double)v_offset * screen.v.y;
	pixel.z = first_pixel.z + (double)u_offset * screen.u.z;
    pixel.z += (double)v_offset * screen.v.z;
	return (pixel);
}

void	ft_get_pixels_coordinates(t_data *data, t_coordinates *pixels)
{
    t_coordinates   first_pixel;
	t_coordinates	pixel;
    t_screen    screen;
	int		i;
    int nb_pixels;
    
    screen = ft_get_screen(data->camera);
	first_pixel = ft_get_first_pixel(screen);
    i = 1;
    nb_pixels = HEIGHT * LENGHT;
    while (i <= nb_pixels)
    {
        pixels[i - 1] = ft_get_pixel(i, screen, first_pixel);
        i++;
    }
	return ;
}

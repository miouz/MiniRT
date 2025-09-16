/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:10:42 by anony             #+#    #+#             */
/*   Updated: 2025/09/16 19:08:51 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_pixel	*ft_get_first_pixel(t_screen *scr)
{
	t_pixel	*pixel;
	double	u_offset;
	double	v_offset;

	pixel = malloc(sizeof(t_pixel *));
	if (!pixel)
		return (NULL);
	if (LENGHT % 2 == 0)
		u_offset = -1.0 * ((double)LENGHT / 2 - 0.5);
	else
		u_offset = -1.0 * ((double)LENGHT / 2);
	if (HEIGHT % 2 == 0)
		v_offset = (double)HEIGHT / 2 - 0.5;
	else
		v_offset = (double)HEIGHT / 2;
	pixel->id = 1;
	pixel->x = scr->center->x + u_offset * scr->u->x + v_offset * scr->v->x;
	pixel->y = scr->center->y + u_offset * scr->u->y + v_offset * scr->v->y;
	pixel->z = scr->center->z + u_offset * scr->u->z + v_offset * scr->v->z;
	return (pixel);
}

t_pixel	*ft_get_pixel(int id, t_screen *screen)
{
	t_pixel	*first_pixel;
	t_pixel	*pixel;
	int		u_offset;
	int		v_offset;

	pixel = malloc(sizeof(t_pixel *));
	if (!pixel)
		return (perror("malloc fail"), exit(EXIT_FAILURE), NULL);
	first_pixel = ft_get_first_pixel(screen);
	if (!first_pixel)
		return (perror("malloc fail"), free(pixel), exit(EXIT_FAILURE), NULL);
    if (id == 1)
        return (first_pixel);
	u_offset = (id - 1) % LENGHT;
	v_offset = -1 * (id - 1) / LENGHT;
	pixel->id = id;
	pixel->x = first_pixel->x + (double)u_offset * screen->u->x;
    pixel->x += (double)v_offset * screen->v->x;
	pixel->y = first_pixel->y + (double)u_offset * screen->u->y;
    pixel->y += (double)v_offset * screen->v->y;
	pixel->z = first_pixel->z + (double)u_offset * screen->u->z;
    pixel->z += (double)v_offset * screen->v->z;
    free(first_pixel);
	return (pixel);
}

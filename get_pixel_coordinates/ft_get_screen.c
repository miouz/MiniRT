/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:54:16 by anony             #+#    #+#             */
/*   Updated: 2025/09/16 19:02:43 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coordinates	*ft_get_screen_center(t_camera *cam)
{
	t_coordinates	*screen_center;
	double		distance;

	screen_center = malloc(sizeof(t_coordinates *));
	if (!screen_center)
		return (NULL);
	distance = (double)(LENGHT / 2) * (double)tan(cam->fov / 2);
	screen_center->type = 1;
	screen_center->x = cam->camera->x + distance * cam->cam_direction->x;
	screen_center->y = cam->camera->y + distance * cam->cam_direction->y;
	screen_center->z = cam->camera->z + distance * cam->cam_direction->z;
	return (screen_center);
}

t_coordinates	*ft_get_u_screen_direction_vector(t_coordinates *cam_dir)
{
	t_coordinates	*u;

	u = malloc(sizeof(t_coordinates *));
	if (!u)
		return (NULL);
	u->type = 0;
	if (cam_dir->x == 0.0 && cam_dir->z == 0)
	{
		u->x = 1;
		u->y = 0;
		u->z = 0;
	}
	else
	{
		u->x = cam_dir->z * (-1);
		u->y = 0;
		u->z = cam_dir->x;
	}
	return (u);
}

t_coordinates	*ft_get_v_screen_direction_vector(t_coordinates *cam_dir, t_coordinates *u)
{
	t_coordinates	*v;

	v = malloc(sizeof(t_coordinates *));
	if (!v)
		return (NULL);
	v->type = 0;
	v->x = u->y * cam_dir->z - u->z * cam_dir->y;
	v->y = u->z * cam_dir->x - u->x * cam_dir->z;
	v->z = u->x * cam_dir->y - u->y * cam_dir->x;
	return (v);
}

t_screen	*ft_get_screen(t_camera *cam)
{
	t_screen	*screen;

	screen = malloc(sizeof(t_screen *));
	if (!screen)
		return (perror("malloc fail"), exit(EXIT_FAILURE), NULL);
	screen->center = ft_get_screen_center(cam);
	screen->u = ft_get_u_screen_direction_vector(cam->cam_direction);
	screen->v = ft_get_v_screen_direction_vector(cam->cam_direction, screen->u);
	if (!screen->center || !screen->u || !screen->v)
	{
		ft_free_screen(screen);
		return (perror("malloc fail"), exit(EXIT_FAILURE), NULL);
	}
	return (screen);
}

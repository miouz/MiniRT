/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:54:16 by anony             #+#    #+#             */
/*   Updated: 2025/10/02 21:06:11 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_coordinates	get_screen_center(t_camera cam)
{
	t_coordinates	screen_center;
	double			distance;
	double			angle;

	angle = (cam.fov / 180.0) * M_PI;
	distance = (double)(LENGHT / 2.0) / (double)tan(angle / 2);
	screen_center.type = 1;
	screen_center.x = cam.center.x + distance * cam.direction.x;
	screen_center.y = cam.center.y + distance * cam.direction.y;
	screen_center.z = cam.center.z + distance * cam.direction.z;
	return (screen_center);
}

t_coordinates	get_u_screen_vector(t_coordinates cam_dir)
{
	t_coordinates	u;

	u.type = 0;
	if (cam_dir.x == 0.0 && cam_dir.z == 0.0)
	{
		u.x = 1;
		u.y = 0;
		u.z = 0;
	}
	else
	{
		u.x = cam_dir.z * (-1);
		u.y = 0;
		u.z = cam_dir.x;
	}
	return (u);
}

t_coordinates	get_v_screen_vector(t_coordinates cam_dir, t_coordinates u)
{
	t_coordinates	v;

	v.type = 0;
	v.x = u.y * cam_dir.z - u.z * cam_dir.y;
	v.y = u.z * cam_dir.x - u.x * cam_dir.z;
	v.z = u.x * cam_dir.y - u.y * cam_dir.x;
	return (v);
}

t_screen	get_screen(t_camera cam)
{
	t_screen	screen;

	screen.center = get_screen_center(cam);
	screen.u = get_u_screen_vector(cam.direction);
	screen.v = get_v_screen_vector(cam.direction, screen.u);
	return (screen);
}

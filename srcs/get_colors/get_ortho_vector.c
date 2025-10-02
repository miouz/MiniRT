/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ortho_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:20:57 by anony             #+#    #+#             */
/*   Updated: 2025/10/02 20:29:00 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_coordinates	get_plane_ortho_vector(t_intersect intersect)
{
	t_plane	plane;

	plane = intersect.obj->data.plane;
	return (plane.ortho_vector);
}

t_coordinates	get_sphere_ortho_vector(t_intersect intersect)
{
	t_sphere			sphere;
	t_coordinates		ortho_vector;
	double				radius;

	sphere = intersect.obj->data.sphere;
	radius = sphere.diameter / 2.0;
	ortho_vector.type = 0;
	ortho_vector.x = (intersect.point.x - sphere.center.x) / radius;
	ortho_vector.y = (intersect.point.y - sphere.center.y) / radius;
	ortho_vector.z = (intersect.point.z - sphere.center.z) / radius;
	return (ortho_vector);
}

t_coordinates	get_cylinder_ortho_vector(t_intersect inter)
{
	t_coordinates		ortho_vector;
	double				ax_comp;
	t_coordinates		center;
	t_coordinates		axis_vector;

	center = inter.obj->data.cylinder.center;
	axis_vector = inter.obj->data.cylinder.axis_vector;
	ax_comp = (inter.point.x - center.x) * axis_vector.x
		+ (inter.point.y - center.y) * axis_vector.y
		+ (inter.point.z - center.z) * axis_vector.z;
	if (fabs(ax_comp) - inter.obj->data.cylinder.height / 2.0 < -1.0 * EPSILON)
	{
		ortho_vector.x = (inter.point.x - (center.x + ax_comp * axis_vector.x))
			/ (inter.obj->data.cylinder.diameter / 2.0);
		ortho_vector.y = (inter.point.y - (center.y + ax_comp * axis_vector.y))
			/ (inter.obj->data.cylinder.diameter / 2.0);
		ortho_vector.z = (inter.point.z - (center.z + ax_comp * axis_vector.z))
			/ (inter.obj->data.cylinder.diameter / 2.0);
		return (ortho_vector);
	}
	if (ax_comp > 0)
		return (axis_vector);
	ortho_vector = vec_scala_multiply(axis_vector, -1.0);
	return (ortho_vector);
}

t_coordinates	get_ortho_vector(t_intersect intersect)
{
	t_coordinates	ortho_vector;

	if (intersect.obj->type == PLANE)
		ortho_vector = get_plane_ortho_vector(intersect);
	if (intersect.obj->type == SPHERE)
		ortho_vector = get_sphere_ortho_vector(intersect);
	if (intersect.obj->type == CYLINDER)
		ortho_vector = get_cylinder_ortho_vector(intersect);
	return (ortho_vector);
}

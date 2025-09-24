/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ortho_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:20:57 by anony             #+#    #+#             */
/*   Updated: 2025/09/22 16:06:18 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"


t_coordinates   ft_get_plane_ortho_vector(t_intersect intersect)
{
    t_plane   plane;
    
    plane = intersect.obj->data.plane;
    return (plane.orhto_vector);
}

t_coordinates   ft_get_sphere_ortho_vector(t_intersect intersect)
{
    t_sphere   sphere;
    t_coordinates   ortho_vector;
    double  radius;

    sphere = intersect.obj->data.sphere;
    radius = sphere.diameter / 2.0;
    ortho_vector.type = 0;
    ortho_vector.x = (intersect.point.x - sphere.center.x) / radius;
    ortho_vector.y = (intersect.point.y - sphere.center.y) / radius;
    ortho_vector.z = (intersect.point.z - sphere.center.z) / radius;
    return (ortho_vector);
}

t_coordinates   ft_get_cylinder_ortho_vector(t_intersect intersect)
{
    t_coordinates   ortho_vector;
    double  axial_component;
    t_coordinates   center;
    t_coordinates   axis_vector;
    double  radius;
    
    center = intersect.obj->data.cylinder.center;
    axis_vector = intersect.obj->data.cylinder.axis_vector;
    radius = intersect.obj->data.cylinder.diameter / 2.0;
    axial_component = (intersect.point.x - center.x) * axis_vector.x;
    axial_component += (intersect.point.y - center.y) * axis_vector.y;
    axial_component += (intersect.point.z - center.z) * axis_vector.z;
    if (absolute_value(axial_component) - intersect.obj->data.cylinder.height / 2.0 < EPSILON)
    {
        if (axial_component > 0)
            return (axis_vector);
        ortho_vector.x = -1.0 * axis_vector.x;
        ortho_vector.y = -1.0 * axis_vector.y;
        ortho_vector.z = -1.0 * axis_vector.z;
        return (ortho_vector);
    }
    ortho_vector.x = (intersect.point.x - center.x + axial_component * axis_vector.x) / radius;
    ortho_vector.y = (intersect.point.y - center.y + axial_component * axis_vector.y) / radius;
    ortho_vector.z = (intersect.point.z - center.z + axial_component * axis_vector.z) / radius;
    return (ortho_vector);
}

// ne l appeler que si intersect.obj n est pas NULL

t_coordinates   ft_get_ortho_vector(t_intersect intersect)
{
    t_coordinates   ortho_vector;

    if (intersect.obj->type == PLANE)
        ortho_vector = ft_get_plane_ortho_vector(intersect);
    if (intersect.obj->type == SPHERE)
        ortho_vector = ft_get_sphere_ortho_vector(intersect);
    if (intersect.obj->type == CYLINDER)
        ortho_vector = ft_get_cylinder_ortho_vector(intersect);
    return (ortho_vector);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:38:44 by anony             #+#    #+#             */
/*   Updated: 2025/09/30 18:02:52 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void setup_data(t_data *data)
{
    t_object *sphere;

    sphere = malloc(sizeof(t_object));
    sphere->color.blue = 0;
    sphere->color.green = 0;
    sphere->color.red = 0;
    sphere->data.sphere.center.type = 1;
    sphere->data.sphere.center.x = 1;
    sphere->data.sphere.center.y = 1;
    sphere->data.sphere.center.z = 1;
    sphere->data.sphere.diameter = 4;
    sphere->type = SPHERE;
    
    data->ambient_lighting.color.blue = 0;
    data->ambient_lighting.color.green = 0;
    data->ambient_lighting.color.red = 0;
    data->ambient_lighting.intensity = 0.2;
    data->camera.center.type = 1;
    data->camera.center.x = 5;
    data->camera.center.y = 5;
    data->camera.center.z = 5;
    data->camera.direction.type = 0;
    data->camera.direction.x = -1;
    data->camera.direction.y = -2;
    data->camera.direction.z = -3;
    data->camera.fov = 120;
    data->light.color.blue = 0;
    data->light.color.green = 0;
    data->light.color.red = 0;
    data->light.intensity = 0.6;
    data->light.source.type = 1;
    data->light.source.x = 8;
    data->light.source.y = 2;
    data->light.source.z = -2;
    data->objects = sphere;
}

int main (int argc, char **argv)
{
    t_data data;
    t_coordinates pixels[HEIGHT * LENGHT];
    t_intersect intersects[HEIGHT * LENGHT];

    setup_data(&data);
    data.pixels = pixels;
    data.intersects = intersects;
    
    get_pixels_coordinates(&data, pixels);
    get_intersect(&data, pixels, intersects);
    get_pixels_colors(&data, intersects, colors);
    convert_colors_for_minilibX(&data, colors);
    blablaminilibX(); // afficher image etc
    clean(data);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:38:44 by anony             #+#    #+#             */
/*   Updated: 2025/10/01 20:21:45 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void setup_data(t_data *data, char **argv)
{
    t_object *sphere;
    t_object *cylinder;

    (void) argv;
    sphere = malloc(sizeof(t_object));
    cylinder = malloc(sizeof(t_object));
    sphere->color.blue = 255;
    sphere->color.green = 0;
    sphere->color.red = 0;
    sphere->data.sphere.center.type = 1;
    sphere->data.sphere.center.x = 0;
    sphere->data.sphere.center.y = 0;
    sphere->data.sphere.center.z = 0;
    sphere->data.sphere.diameter = 6;
    sphere->type = SPHERE;
    cylinder->type = CYLINDER;
    cylinder->data.cylinder.center.type = 1;
    cylinder->data.cylinder.center.x = 0;
    cylinder->data.cylinder.center.y = 0;
    cylinder->data.cylinder.center.z = 0;
    cylinder->data.cylinder.diameter = 3;
    cylinder->color.blue = 255;
    cylinder->color.green = 0;
    cylinder->color.red = 0;
    cylinder->data.cylinder.height = 7;
    cylinder->data.cylinder.axis_vector.type = 1;
    cylinder->data.cylinder.axis_vector.x = 1;
    cylinder->data.cylinder.axis_vector.y = 0;
    cylinder->data.cylinder.axis_vector.z = 0;
    
    data->ambient_lighting.color.blue = 255;
    data->ambient_lighting.color.green = 255;
    data->ambient_lighting.color.red = 255;
    data->ambient_lighting.intensity = 0.1;
    data->camera.center.type = 1;
    data->camera.center.x = 0;
    data->camera.center.y = 0;
    data->camera.center.z = 5;
    data->camera.direction.type = 0;
    data->camera.direction.x = -1;
    data->camera.direction.y = -1;
    data->camera.direction.z = -1;
    data->camera.fov = 150;
    data->light.color.blue = 255;
    data->light.color.green = 255;
    data->light.color.red = 255;
    data->light.intensity = 0.8;
    data->light.source.type = 1;
    data->light.source.x = 8;
    data->light.source.y = -2;
    data->light.source.z = 22;
    data->objects = cylinder;
    data->nb_objects = 1;
}

int main (int argc, char **argv)
{
    t_data data;
    t_coordinates *pixels;
    t_intersect *intersects;

    pixels = malloc((HEIGHT * LENGHT) * sizeof(t_coordinates));
    intersects = malloc((HEIGHT * LENGHT) * sizeof(t_intersect));
    (void) argc;
    setup_data(&data, argv);
    data.pixels = pixels;
    data.intersects = intersects;
    initialize_minilibx(&data.minilibx);
    printf("%p\n", data.minilibx.colors);
    get_pixels_coordinates(&data);
    get_intersects(&data);
    get_colors(&data, data.minilibx.line);
	mlx_put_image_to_window(data.minilibx.mlx_p, data.minilibx.win_p, data.minilibx.img_p, 0, 0);
    mlx_loop(data.minilibx.mlx_p);
    
    // clean(data);
    return (0);
}

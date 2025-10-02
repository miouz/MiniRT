/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:38:44 by anony             #+#    #+#             */
/*   Updated: 2025/10/02 19:11:42 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void setup_data(t_data *data, char **argv)
{
    t_object *sphere;
    t_object *cylinder;
    t_object *scene;

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
    data->ambient_lighting.intensity = 0.3;
    data->camera.center.type = 1;
    data->camera.center.x = 0;
    data->camera.center.y = 0;
    data->camera.center.z = 20;
    data->camera.direction.type = 0;
    data->camera.direction.x = 0;
    data->camera.direction.y = 0;
    data->camera.direction.z = -1.0;
    data->camera.fov = 120;
    data->light.color.blue = 255;
    data->light.color.green = 255;
    data->light.color.red = 255;
    data->light.intensity = 0.8;
    data->light.source.type = 1;
    data->light.source.x = -15;
    data->light.source.y = 20;
    data->light.source.z = 6;


    scene = malloc(7 * (sizeof(t_object)));
    scene[1].type = CYLINDER;
    scene[1].data.cylinder.center.type = 1;
    scene[1].data.cylinder.center.x = 0;
    scene[1].data.cylinder.center.y = 3;
    scene[1].data.cylinder.center.z = 0;
    scene[1].data.cylinder.diameter = 4;
    scene[1].color.red = 0;
    scene[1].color.green = 0;
    scene[1].color.blue = 255;
    scene[1].data.cylinder.height = 16;
    scene[1].data.cylinder.axis_vector.type = 1;
    scene[1].data.cylinder.axis_vector.x = 0.0;
    scene[1].data.cylinder.axis_vector.y = 1.0;
    scene[1].data.cylinder.axis_vector.z = 0.0;

    scene[0].type = SPHERE;
    scene[0].color.red = 0;
    scene[0].color.green = 0;
    scene[0].color.blue = 255;
    scene[0].data.sphere.center.type = 1;
    scene[0].data.sphere.center.x = 2.5;
    scene[0].data.sphere.center.y = -5;
    scene[0].data.sphere.center.z = 0;
    scene[0].data.sphere.diameter = 7.4;

    scene[2].type = SPHERE;
    scene[2].color.red = 0;
    scene[2].color.green = 0;
    scene[2].color.blue = 255;
    scene[2].data.sphere.center.type = 1;
    scene[2].data.sphere.center.x = -2.5;
    scene[2].data.sphere.center.y = -5;
    scene[2].data.sphere.center.z = 0;
    scene[2].data.sphere.diameter = 7.2;

    scene[3].type = SPHERE;
    scene[3].color.red = 0;
    scene[3].color.green = 0;
    scene[3].color.blue = 255;
    scene[3].data.sphere.center.type = 1;
    scene[3].data.sphere.center.x = 0;
    scene[3].data.sphere.center.y = 11;
    scene[3].data.sphere.center.z = 0;
    scene[3].data.sphere.diameter = 5;

    scene[4].type = PLANE;
    scene[4].color.red = 120;
    scene[4].color.green = 30;
    scene[4].color.blue = 30;
    scene[4].data.plane.ortho_vector.type = 0;
    scene[4].data.plane.ortho_vector.x = 1.0;
    scene[4].data.plane.ortho_vector.y = 0;
    scene[4].data.plane.ortho_vector.z = 0;
    scene[4].data.plane.point.type = 1;
    scene[4].data.plane.point.x = -20;
    scene[4].data.plane.point.y = 0;
    scene[4].data.plane.point.z = 0;

    scene[5].type = PLANE;
    scene[5].color.red = 120;
    scene[5].color.green = 30;
    scene[5].color.blue = 30;
    scene[5].data.plane.ortho_vector.type = 0;
    scene[5].data.plane.ortho_vector.x = 0;
    scene[5].data.plane.ortho_vector.y = 1.0;
    scene[5].data.plane.ortho_vector.z = 0;
    scene[5].data.plane.point.type = 1;
    scene[5].data.plane.point.x = 0;
    scene[5].data.plane.point.y = -20;
    scene[5].data.plane.point.z = 0;
    
    scene[6].type = PLANE;
    scene[6].color.red = 120;
    scene[6].color.green = 30;
    scene[6].color.blue = 30;
    scene[6].data.plane.ortho_vector.type = 0;
    scene[6].data.plane.ortho_vector.x = 0;
    scene[6].data.plane.ortho_vector.y = 0;
    scene[6].data.plane.ortho_vector.z = 1.0;
    scene[6].data.plane.point.type = 1;
    scene[6].data.plane.point.x = 0;
    scene[6].data.plane.point.y = 0;
    scene[6].data.plane.point.z = -20;
    
    data->objects = scene;
    data->nb_objects = 7;
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
    get_pixels_coordinates(&data);
    get_intersects(&data);
    get_colors(&data, data.minilibx.line);
	mlx_put_image_to_window(data.minilibx.mlx_p, data.minilibx.win_p,
        data.minilibx.img_p, 0, 0);
    mlx_loop(data.minilibx.mlx_p);
    
    // clean(data);
    return (0);
}

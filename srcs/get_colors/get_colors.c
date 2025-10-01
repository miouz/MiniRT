/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:20:58 by anony             #+#    #+#             */
/*   Updated: 2025/10/01 19:58:06 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_boolean   is_enlightened(t_data *data, t_ray *light_ray)
{
    int    obj;
    t_object *object;
    double  distance;
    
    obj = 0;
    distance = vec_magnitude(light_ray->direction);
    object = data->objects;
    while (obj < data->nb_objects)
    {  
        if (object->type == PLANE
            && get_ray_plane_intersect_time(&object->data.plane, light_ray) < 1.0 - EPSILON)
            return (FALSE);
        if (object->type == SPHERE
            && get_ray_sphere_intersect_time(&object->data.sphere, light_ray) < 1.0 - EPSILON)
            return (FALSE);
        if (object->type == CYLINDER
            && get_ray_cylinder_intersect_time(&object->data.cylinder, light_ray) < 1.0 - EPSILON)
            return (FALSE);
        object++;
        obj++;
    }
    return (TRUE);
}

void    fill_light_ray(t_data *data, int ind, t_ray *light_ray)
{
    light_ray->direction.x = data->intersects[ind].point.x - data->light.source.x;
    light_ray->direction.y = data->intersects[ind].point.y - data->light.source.y;
    light_ray->direction.z = data->intersects[ind].point.z - data->light.source.z;
    light_ray->origin = data->light.source;
}

t_color get_pixel_color(t_data *data, int x, int y)
{
    t_ray   light_ray;
    t_coordinates   ortho_vector;
    t_color color;
    double  intensity;

    fill_light_ray(data, y * LENGHT + x, &light_ray);
    if (!data->intersects[y * LENGHT + x].obj)
    {
        color.blue = (int)(data->ambient_lighting.color.blue * data->ambient_lighting.intensity);
        color.green = (int)(data->ambient_lighting.color.green * data->ambient_lighting.intensity);
        color.red = (int)(data->ambient_lighting.color.red * data->ambient_lighting.intensity);
        return (color);
    }
    ortho_vector = get_ortho_vector(data->intersects[y * LENGHT + x]);
    if (is_enlightened(data, &light_ray))
        intensity = data->ambient_lighting.intensity
            - vec_dot_product(ortho_vector, light_ray.direction) * data->light.intensity
            / vec_magnitude(light_ray.direction);
    else
        intensity = data->ambient_lighting.intensity;
    if (intensity > 1.0)
        intensity = 1.0;
    color.red = (int)(intensity * data->intersects[y * LENGHT + x].obj->color.red);
    if (color.red > 255)
        color.red = 255;
    color.green = (int)(intensity * data->intersects[y * LENGHT + x].obj->color.green);
    if (color.green > 255)
        color.green = 255;
    color.blue = (int)(intensity * data->intersects[y * LENGHT + x].obj->color.blue);
    if (color.blue > 255)
        color.blue = 255;
    return (color);
}

void    get_colors(t_data *data, int size_line)
{
    int x;
    int y;
    int offset;
    t_color color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < LENGHT)
        {
            offset = y * size_line + x * 4;
            color = get_pixel_color(data, x, y);
            // printf("Pixel %d : red - %d - green - %d - blue : - %d -\n", offset, color.red, color.green, color.blue);
            data->minilibx.colors[offset] = (char)color.red; 
            data->minilibx.colors[offset + 1] = (char)color.green;
            data->minilibx.colors[offset + 2] = (char)color.blue;
            x++;
        }
        y++;
    }
}

/*
int color = (r << 16) | (g << 8) | b;

*((int *)(img_data + offset)) = color;

exemple :
color     = 11111111 01100100 00011001
mask      = 11111111 00000000 00000000
-------------------------------------
resultat  = 11111111 00000000 00000000 = 0xFF0000



img_data[offset + 0] = (color & 0x0000FF);        // Bleu
img_data[offset + 1] = (color & 0x00FF00) >> 8;   // Vert
img_data[offset + 2] = (color & 0xFF0000) >> 16;  // Rouge
img_data[offset + 3] = 0;                         // Alpha (optionnel)


void	render_scene(void *mlx_ptr, void *win_ptr)
{
	void	*img;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;

	img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			int color = get_pixel_color(x, y); // fonction perso
			set_pixel(img_data, x, y, color, size_line);
		}
	}

	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
}
void	set_pixel(char *img_data, int x, int y, int color, int size_line)
{
	int	offset;

	offset = (y * size_line) + (x * 4); // 4 = bytes per pixel (assuming 32-bit color)
	img_data[offset + 0] = (color & 0x0000FF);        // Blue
	img_data[offset + 1] = (color & 0x00FF00) >> 8;   // Green
	img_data[offset + 2] = (color & 0xFF0000) >> 16;  // Red
	// +3: alpha (souvent inutilisé dans MLX)
}

*/

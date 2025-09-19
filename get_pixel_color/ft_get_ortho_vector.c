/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ortho_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:20:57 by anony             #+#    #+#             */
/*   Updated: 2025/09/19 17:18:20 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"


t_coordinates   ft_get_plane_ortho_vector(t_intersect intersect)
{
    t_plane   *plane;
    
    plane = (t_plane *)intersect.obj->data;
    return (plane->orhto_vector);
}

t_coordinates   ft_get_sphere_ortho_vector(t_intersect intersect)
{
    t_sphere   *sphere;
    t_coordinates   ortho_vector;
    double  radius;

    sphere = (t_sphere *)intersect.obj->data;
    radius = sphere->diameter / 2.0;
    ortho_vector.type = 0;
    ortho_vector.x = (intersect.x - sphere->center.x) / radius;
    ortho_vector.y = (intersect.y - sphere->center.y) / radius;
    ortho_vector.z = (intersect.z - sphere->center.z) / radius;
    return (ortho_vector);
}

t_coordinates   ft_get_cylinder_ortho_vector(t_intersect intersect)
{
    t_coordinates   *ortho_vector;
    

    return (ortho_vector);
}

t_coordinates   ft_get_ortho_vector(t_intersect intersect)
{
    t_coordinates   ortho_vector;

    if (intersect->obj == NULL)
       dlkfjhgkjsdfhg
    if (intersect->obj->type == PLANE)
        ortho_vector = ft_get_plane_ortho_vector(intersect);
    if (intersect->obj->type == SPHERE)
        ortho_vector = ft_get_sphere_ortho_vector(intersect);
    if (intersect->obj->type == CYLINDER)
        ortho_vector = ft_get_cylinder_ortho_vector(intersect);
    free(intersect);
    return (ortho_vector);
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
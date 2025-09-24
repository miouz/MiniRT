/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:37:40 by anony             #+#    #+#             */
/*   Updated: 2025/09/23 13:58:08 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define HEIGHT 400
# define LENGHT 800
# define EPSILON 0.00001

// id varie de 1 au nombre de pixel max, la numerotation se fait ligne par ligne

// typedef struct s_pixel
// {
// 	int		id;
// 	double	x;
// 	double	y;
// 	double	z;
// }	t_pixel;

// type = 1 pour un point et 0 pour un vecteur

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
	int		type;
}	t_coordinates;

typedef struct s_minilibx_data
{
    void *mlx_p;
    void *win_p;
    void *img_p;
    char *dat;
    int bpp;
    int line;
    int end;
}	t_minilibx_data;

typedef struct s_data
{
    t_camera    camera;
    t_ambient_lighting ambient_lighting;
    t_light     light;
    t_object    *objects;
    t_coordinates pixels[HEIGHT * LENGHT];
    t_intersect intersects[HEIGHT * LENGHT];
	char	*colors;
}   t_data;

// structures des differentes infos du parsing :

typedef struct s_camera
{
	t_coordinates	center;
	t_coordinates	direction;
	int			fov;
}	t_camera;

typedef struct s_ray
{
	t_coordinates	origin;
	t_coordinates	direction;
}	t_ray;

typedef struct s_ambient_lighting
{
	double  intensity;
    t_color color;      // au cas où mais pas utile dans la mandatory part
}	t_ambient_lighting;

typedef struct s_light
{
	double  intensity;
    t_coordinates   source;
    t_color color;      // au cas où mais pas utile dans la mandatory part
}	t_light;

typedef struct s_object
{
	t_type	type;
	t_object_union	data;
	t_color color; 
}	t_object;

typedef	union u_object_union
{
	t_plane	plane;
	t_sphere	sphere;
	t_cylinder	cylinder;
}	t_object_union;

typedef struct s_plane
{
	t_coordinates	point;
	t_coordinates   orhto_vector;
}	t_plane;

typedef struct s_sphere
{
	t_coordinates	center;
	double   diameter;
}	t_sphere;

typedef struct s_cylinder
{
	t_coordinates	center;
	t_coordinates	axis_vector;
	double   diameter;
	double   height;
}	t_cylinder;

// u et v vecteurs directeurs du plan contenant l ecran. u est orthogonal a l axe y vertical du repere orthonorme de la scene.

typedef struct s_screen
{
	t_coordinates	center;
	t_coordinates	u;
	t_coordinates	v;
}	t_screen;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef enum e_boolean
{
	FALSE,
	TRUE
}	t_boolean;

// typedef struct s_object
// {
// 	t_type		type;
// 	t_coordinates	center;
// 	double		diameter;
// 	t_color		color;
// 	t_coordinates	ortho_vector;
// 	t_coordinates	dir_vector;
// 	double		height;
// }	t_object;

typedef struct s_intersect
{
	t_coordinates	point;
	t_object	*obj;
}	t_intersect;

// utils.c

double  absolute_value(double   nb);


// ft_get_screen.c

t_screen	ft_get_screen(t_camera cam);

// ft_get_ortho_vector.c

t_coordinates   ft_get_ortho_vector(t_intersect intersect);

#endif

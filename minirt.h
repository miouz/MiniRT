/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriennony <adriennony@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:37:40 by anony             #+#    #+#             */
/*   Updated: 2025/09/18 18:45:34 by adriennony       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define HEIGHT 400
# define LENGHT 800

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


typedef struct s_data
{
    t_camera    camera;
    t_ambient_lighting ambient_lighting;
    t_light     light;
    t_object    *object;
}   t_data;

// structures des differentes infos du parsing :

typedef struct s_camera
{
	t_coordinates	center;
	t_coordinates	direction;
	int			fov;
}	t_camera;

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
	void	*data;
	struct s_object    *next;
}	t_object;

typedef struct s_plane
{
	t_coordinates	point;
	t_coordinates   orhto_vector;
	t_color color; 
}	t_plane;

typedef struct s_sphere
{
	t_coordinates	center;
	double   diameter;
	t_color color; 
}	t_sphere;

typedef struct s_cylinder
{
	t_coordinates	center;
	t_coordinates	axis_vector;
	double   diameter;
	double   height;
	t_color color; 
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
	double	x;
	double	y;
	double	z;
	t_object	*obj;
}	t_intersect;

// utils.c

// void    ft_free_camera(t_camera *cam);
// void    ft_free_screen(t_screen *screen);


// ft_get_screen.c

t_screen	ft_get_screen(t_camera cam);

#endif

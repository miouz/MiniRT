/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:18:52 by anony             #+#    #+#             */
/*   Updated: 2025/10/01 19:30:42 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define HEIGHT 800
# define LENGHT 800
# define EPSILON 0.00001
#define M_PI 3.14159265358979323846

/*==================================MINILIBX_DATA===========================*/
typedef struct s_minilibx_data
{
	void	*mlx_p;
	void	*win_p;
	void	*img_p;
	char	*colors;
	int		bpp;
	int		line;
	int		end;
}	t_minilibx_data;

/*==================================VECTOR_STRUCTS===========================*/
typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
	int		type;
}	t_coordinates;

/*==================================OBJECT_DATA===========================*/

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef enum e_boolean
{
	FALSE,
	TRUE
}	t_boolean;

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_plane
{
	t_coordinates	point;
	t_coordinates	ortho_vector;
}	t_plane;

typedef struct s_sphere
{
	t_coordinates	center;
	double			diameter;
}	t_sphere;

typedef struct s_cylinder
{
	t_coordinates	center;
	t_coordinates	axis_vector;
	double			diameter;
	double			height;
}	t_cylinder;

typedef union u_object_union
{
	t_plane		plane;
	t_sphere	sphere;
	t_cylinder	cylinder;
}	t_object_union;

typedef struct s_object
{
	t_type			type;
	t_object_union	data;
    t_color         color;
}	t_object;

typedef struct s_intersect
{
	t_coordinates	point;
	t_object		*obj;
}	t_intersect;

/*==================================SCENE_INFOS===========================*/

typedef struct s_camera
{
	t_coordinates	center;
	t_coordinates	direction;
	int				fov;
}	t_camera;

typedef struct s_ray
{
	t_coordinates	origin;
	t_coordinates	direction;
}	t_ray;

typedef struct s_ambient_lighting
{
	double	intensity;
	t_color	color;
}	t_ambient_lighting;

typedef struct s_light
{
	double			intensity;
	t_coordinates	source;
	t_color			color;
}	t_light;

// u et v vecteurs directeurs du plan contenant l ecran. 
// u est orthogonal a l axe y vertical du repere orthonorme de la scene.
typedef struct s_screen
{
	t_coordinates	center;
	t_coordinates	u;
	t_coordinates	v;
}	t_screen;

typedef struct s_data
{
	t_camera			camera;
	t_ambient_lighting	ambient_lighting;
	t_light				light;
	t_object			*objects;
	int					nb_objects;
	t_coordinates		*pixels;
	t_intersect			*intersects;
	t_minilibx_data		minilibx;
}	t_data;

#endif

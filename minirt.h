/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:37:40 by anony             #+#    #+#             */
/*   Updated: 2025/09/16 15:15:54 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

# include <math.h>
# include <stdio.h>

# define HEIGHT 400
# define LENGHT 800

// id varie de 1 au nombre de pixel max, la numerotation se fait ligne par ligne

typedef struct s_pixel
{
    int     id;
    double  x;
    double  y;
    double  z;
}   t_pixel;

// type = 1 pour un point et 0 pour un vecteur

typedef struct s_coordinates
{
    double  x;
    double  y;
    double  z;
    int     type;
}   t_coordinates;

typedef struct s_camera
{
    t_coordinates   *camera;
    t_coordinates   *cam_direction;
    int             fov;
}   t_camera;

// u et v vecteurs directeurs du plan contenant l ecran. u est orthogonal a l axe y vertical du repere orthonorme de la scene.

typedef struct s_screen
{
    t_coordinates   *center;
    t_coordinates   *u;
    t_coordinates   *v;
}   t_screen;

typedef struct s_color
{
    int red;
    int green;
    int blue;
}   t_color;

typedef enum e_type
{
    SPHERE,
    PLANE,
    CYLINDER
}   t_type;

typedef struct s_object
{
    t_type type;
    t_coordinates   center;
    double  diameter;
    t_color color;
    t_coordinates   ortho_vector;
    t_coordinates   dir_vector;
    double  height;
}   t_object;

typedef struct s_intersect
{
    double  x;
    double  y;
    double  z;
    t_object    obj;
}   t_intersect;

#endif
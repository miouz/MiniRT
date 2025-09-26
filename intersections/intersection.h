/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:59:21 by mzhou             #+#    #+#             */
/*   Updated: 2025/09/16 15:59:21 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
# define SCENE_OBJECT_QUANTITIES 7
# define TIME_VAL_NO_INTERSECTION -1

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

double	get_time_from_discriminant(double a, double b, double discriminant);
double	get_ray_plane_intersect_time(t_plane *plane, t_ray *ray);
double	get_ray_cylinder_intersect_time(t_cylinder *cylinder, t_ray *ray);
double	get_ray_sphere_intersect_time(t_sphere *sphere, t_ray *ray);
int		get_hit_point(t_intersect *intersect_point, t_ray *ray, t_object *scene);
#endif

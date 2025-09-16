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

# include <unistd.h>
# include <stdlib.h>
# include "../minirt.h"

typedef struct s_ray
{
	t_coordinates	origin;
	t_coordinates	direction;
}	t_ray;

typedef struct s_intersect
{
    double  	t;
    t_object    obj;
}   t_intersect;

int	get_hit_point(t_intersect *intersect_point, t_ray *ray, t_object *scene);
#endif

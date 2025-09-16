/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:33:08 by anony             #+#    #+#             */
/*   Updated: 2025/09/16 18:54:46 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void    ft_free_camera(t_camera *cam)
{
    if (!cam)
        return ;
    if (cam->cam_direction)
        free(cam->cam_direction);
    if (cam->camera)
        free(cam->camera);
    free(cam);
    return ;
}

void    ft_free_screen(t_screen *screen)
{
    if (!screen)
        return ;
    if (screen->center)
        free(screen->center);
    if (screen->u)
        free(screen->u);
    if (screen->v)
        free(screen->v);
    free(screen);
    return ;
}
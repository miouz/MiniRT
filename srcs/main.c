/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:38:44 by anony             #+#    #+#             */
/*   Updated: 2025/09/19 16:36:16 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int main (int argc, char **argv)
{
    t_data data;
    t_coordinates pixels[HEIGHT * LENGHT];
    t_intersect intersects[HEIGHT * LENGHT];
    t_color colors[HEIGHT * LENGHT];

    setup_data(&data);
    get_pixels_coordinates(&data, pixels);
    get_intersect(&data, pixels, intersects);
    get_pixels_colors(&data, intersects, colors);
    convert_colors_for_minilibX(&data, colors);
    blablaminilibX(); // afficher image etc
    clean(data);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriennony <adriennony@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:38:44 by anony             #+#    #+#             */
/*   Updated: 2025/09/18 18:00:43 by adriennony       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main (int argc, char **argv)
{
    t_data data;
    t_coordinates pixels[HEIGHT * LENGHT];
    t_intersect intersects[HEIGHT * LENGHT];
    t_color colors[HEIGHT * LENGHT];

    ft_setup_data(&data);
    ft_get_pixels_coordinates(&data, pixels);
    ft_get_intersect(&data, pixels, intersects);
    ft_get_pixels_colors(&data, intersects, colors);
    ft_convert_colors_for_minilibX(&data, colors);
    ft_blablaminilibX(); // afficher image etc
    ft_free(data);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixels_coordinates.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:34:29 by mzhou             #+#    #+#             */
/*   Updated: 2025/09/30 14:34:29 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_PIXELS_COORDINATES_H
# define GET_PIXELS_COORDINATES_H

void			get_pixels_coordinates(struct s_data *data,
					struct s_coordinates *pixels);
struct s_screen	get_screen(struct s_camera cam);

#endif // !GET_PIXELS_COORDINATES_H

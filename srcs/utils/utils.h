/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:47:39 by anony             #+#    #+#             */
/*   Updated: 2025/10/02 20:52:54 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_strlen(char *str);
void	error_msg(char *str);
int		keyboard_event(int keycode, t_data *data);
int		close_minilibx(t_minilibx_data *data);
void	initialize_minilibx(t_minilibx_data *minilibx);
int		free_data_and_exit(t_data *data);
void	display_empty_window(t_data *data);
int		init_pixel_intersects(t_data *data);

#endif

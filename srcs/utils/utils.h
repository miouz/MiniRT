/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:47:39 by anony             #+#    #+#             */
/*   Updated: 2025/10/01 17:52:11 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int	ft_strlen(char *str);
void  error_msg(char *str);
int	close_minilibx(t_minilibx_data *data);
void	initialize_minilibx(t_minilibx_data *minilibx);

#endif
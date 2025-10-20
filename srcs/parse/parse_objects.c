/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:36:13 by mzhou             #+#    #+#             */
/*   Updated: 2025/10/20 11:36:13 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	parse_ambient_light(char *rest, t_data *data)
{
	static bool	one_ambient_light;

	if (one_ambient_light == true)
		return (error_msg(ERROR_AML), EXIT_FAILURE);
	if (get_next_double_in_range(
			&rest, &data->ambient_lighting.intensity, 0, 1) == EXIT_SUCCESS
		&& get_next_color(
			&rest, &data->ambient_lighting.color) == EXIT_SUCCESS
		&& no_info_in_rest_of_line(rest) == true)
		return (one_ambient_light = true, EXIT_SUCCESS);
	return (error_msg(ERROR_AML), EXIT_FAILURE);
}

int	parse_camera(char *rest, t_data *data)
{
	static bool	one_camera;

	if (one_camera == true)
		return (error_msg(ERROR_CAM), EXIT_FAILURE);
	if (get_next_coordinates(&rest, &data->camera.center) == EXIT_SUCCESS
		&& get_next_vector(&rest, &data->camera.direction) == EXIT_SUCCESS
		&& get_next_int_in_range(&rest, &data->camera.fov, 0, 180)
		== EXIT_SUCCESS)
		return (one_camera = true, EXIT_SUCCESS);
	return (error_msg(ERROR_CAM), EXIT_FAILURE);
}

int	parse_light(char *rest, t_data *data)
{
	if (data->one_spot_light == true)
		return (error_msg(ERROR_LIGHT), EXIT_FAILURE);
	if (get_next_coordinates(&rest, &data->light.source) == EXIT_SUCCESS
		&& get_next_double_in_range(&rest,
			&data->light.intensity, 0, 1) == EXIT_SUCCESS
		&& get_next_color(&rest, &data->light.color) == EXIT_SUCCESS)
		return (data->one_spot_light = true, EXIT_SUCCESS);
	return (error_msg(ERROR_LIGHT), EXIT_FAILURE);
}

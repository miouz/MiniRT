/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:01:39 by mzhou             #+#    #+#             */
/*   Updated: 2025/10/20 10:50:13 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	forward_str_get_int(char **line, char **begin)
{
	*begin = *line;
	if (**line == '\0')
		return (EXIT_FAILURE);
	if (**line == '-')
		(*line)++;
	if (ft_isdigit(**line) == false)
		return (EXIT_FAILURE);
	while (ft_isdigit(**line) == true)
		(*line)++;
	return (EXIT_SUCCESS);
}

int	get_next_int_in_range(char **line, int *result, int min, int max)
{
	char	*begin;

	if (check_and_jump_spaces(line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (forward_str_get_int(line, &begin) == EXIT_SUCCESS
		&& swap_nul_and_atoi(result, begin, *line) == EXIT_SUCCESS
		&& int_is_in_range(*result, min, max) == true)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	get_next_color(char **line, t_color *color)
{
	char	*begin;
	int		result[3];
	int		index;

	index = 0;
	if (check_and_jump_spaces(line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (index <= 2
		&& forward_str_get_int(line, &begin) == EXIT_SUCCESS
		&& swap_nul_and_atoi(&result[index], begin, *line) == EXIT_SUCCESS
		&& int_is_in_range(result[index], 0, 255) == true)
	{
		if (index <= 1 && **line == ',')
		{
			index++;
			(*line)++;
		}
		else if (index == 2 && (**line == '\0'
				|| is_white_space(**line) == true))
			return (*color = (t_color){result[0], result[1], result[2]},
			EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

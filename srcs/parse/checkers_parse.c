/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:53:52 by mzhou             #+#    #+#             */
/*   Updated: 2025/10/20 15:53:52 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	is_normalized_vector(t_coordinates vector)
{
	if (vec_magnitude(vector) - 1 < EPSILON)
		return (true);
	return (false);
}

bool	int_is_in_range(int value, int min, int max)
{
	if (value >= min && value <= max)
		return (true);
	return (false);
}

bool	double_is_in_range(double value, double min, double max)
{
	if (value >= min && value <= max)
		return (true);
	return (false);
}

bool	is_negative_sign(char c)
{
	if (c == '-')
		return (true);
	return (false);
}

/**
 * @brief jump all white spaces and check
 * if any other non-parsed info in the rest of string
 *
 * @param str address point to string
 * @return true if there is , false if not
 */
bool	no_info_in_rest_of_line(char *str)
{
	while (is_white_space(*str) == true)
		str++;
	if (*str == '\0')
		return (true);
	return (false);
}

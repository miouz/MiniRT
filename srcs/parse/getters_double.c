#include "../includes/minirt.h"

/**
 * @brief the function move line points to and 
 * get next double value in min and max range 
 *
 * @param line address of the initial line pointer
 * @param num address of the int to write the parsed value
 * @param min min value in range
 * @param max max value in range
 * @return EXIT_SUCCESS or EXIT_FAILURE if format error
 * @warning the function changes the address pointed by line
 * to the character after the parsed double value in string
 */
int	get_next_double_in_range(char **line, double *num, double min, double max)
{
	if (check_and_jump_spaces(line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_atod_check_format(*line, num) == EXIT_SUCCESS)
	{
		if (double_is_in_range(*num, min, max) == true)
		{
			while (is_negative_sign(**line) == true
				|| ft_isdigit(**line) == true
				|| **line == '.')
				(*line)++;
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

int	iterate_str_get_3doubles(char **line, double *result)
{
	char	*begin;
	int		index;

	begin = *line;
	index = 0;
	while (**line
		&& (ft_isdigit(**line) == true || **line == '.' || **line == '-'))
	{
		(*line)++;
		if ((index <= 1 && **line == ',') || (index == 2
				&& (**line == '\0' || is_white_space(**line) == true)))
		{
			if (swap_nul_and_atod(&result[index], begin, *line)
				== EXIT_FAILURE)
				return (EXIT_FAILURE);
			if (index == 2)
				return (EXIT_SUCCESS);
			index++;
			begin = *line + 1;
			if (**line)
				(*line)++;
		}
	}
	return (EXIT_FAILURE);
}

int	get_next_coordinates(char **line, t_coordinates *value)
{
	double	result[3];

	if (check_and_jump_spaces(line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (iterate_str_get_3doubles(line, result) == EXIT_SUCCESS)
		return (*value = (t_coordinates){result[0], result[1], result[2]},
			EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	get_next_vector(char **line, t_coordinates *value)
{
	if (get_next_coordinates(line, value) == EXIT_SUCCESS
		&& is_normalized_vector(*value) == true)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

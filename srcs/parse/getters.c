// #include "../includes/minirt.h"
#include "parse.h"

int	check_and_jump_spaces(char **line)
{
	if (**line == '\0' || is_white_space(**line) == false)
		return (EXIT_FAILURE);
	while (is_white_space(**line) == true)
		(*line)++;
	return (EXIT_SUCCESS);
}

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
		if (*num >= min && *num <= max)
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

int	get_next_color(char **line, t_color *color)
{
	char	*begin;
	int		result[3];
	int		index;

	index = 0;
	if (check_and_jump_spaces(line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_good_color_format(*line) == true)
	{
		begin = *line;
		while ((*line)++ && index <= 2)
		{
			if (**line == ',' || **line == '\0'
				|| is_white_space(**line) == true)
			{
				swap_nul_and_atoi(&result[index++], begin, *line);
				begin = *line + 1;
			}
		}
	}
	if (result[0] >= 0 && result[0] <= 255 && result[1] >= 0
		&& result[1] <= 255 && result[2] >= 0 && result[2] <= 255)
		return (*color = (t_color){result[0], result[1], result[2]},
			EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// {
// 	return (EXIT_FAILURE);
// }

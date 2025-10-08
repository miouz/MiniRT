// #include "../includes/minirt.h"
#include "parse.h"
# define EPSILON 0.000001

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
	if (**line == '\0' || is_white_space(**line) == false)
		return (EXIT_FAILURE);
	//jump all white_space
	while (is_white_space(**line) == true)
		(*line)++;
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

// int	get_next_color(char *line, t_color *color)
// {
// 	return (EXIT_FAILURE);
// }

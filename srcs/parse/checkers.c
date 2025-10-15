// #include "../includes/minirt.h"
#include "parse.h"

// bool	is_good_color_format(char *line)
// {
// 	int	colors_count;
// 	int	digit_count;
//
// 	colors_count = 0;
// 	digit_count = 0;
// 	while (*line && ft_isdigit(*line) == true)
// 	{
// 		digit_count++;
// 		line++;
// 		if ((*line == ',' && colors_count <= 1) || (colors_count == 2
// 				&& (*line == '\0' || is_white_space(*line) == true)))
// 		{
// 			if (digit_count <= 3 && digit_count >= 1)
// 			{
// 				digit_count = 0;
// 				colors_count++;
// 			}
// 			if (*line)
// 				line++;
// 		}
// 	}
// 	if (colors_count == 3)
// 		return (true);
// 	return (false);
// }

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

/**
 * @brief jump all white spaces and check if any other non-parsed info in the rest of string
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

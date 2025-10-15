// #include "../includes/minirt.h"
#include "parse.h"

bool	is_normalized_vector(t_coordinates vector)
{
	if (vec_magnitude(vector) == 1)
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

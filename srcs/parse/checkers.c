#include "../includes/minirt.h"

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

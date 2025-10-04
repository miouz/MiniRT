#include "../includes/minirt.h"

int	parse_ambient_light(char *rest, t_data *data)
{
	if (get_next_double_in_range(
			rest, &data->ambient_lighting.intensity, 0, 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_next_color(
			rest, &data->ambient_lighting.color) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (no_info_in_rest_of_line(rest) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

#include "../includes/minirt.h"

bool	is_valid_arg(int argc, char **argv)
{
	int	size;
	int	pos_point;

	if (argc != 2)
		return (error_msg(ERROR_ARG_NUM), false);
	size = ft_strlen(argv[1]);
	pos_point = size - 3;
	if (ft_strncmp(argv[1] + pos_point, ".rt", 4) != 0)
		return (error_msg(ERROR_ARG_FORMAT), false);
	return (true);
}

bool	scene_is_valid(t_data *data, int *obj_count)
{
	if (data->nb_objects == 0)
		return (error_msg(ERROR_NO_GEOMETRY), false);
	if (obj_count[0] != 1
		|| obj_count[1] != 1
		|| obj_count[2] > 1)
		return (error_msg(ERROR_NO_3_OBJ), false);
	return (true);
}

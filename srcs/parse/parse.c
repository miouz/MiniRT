
#include "../includes/minirt.h"
#include "parse.h"

bool	is_valid_arg(int argc, char **argv)
{
	int	size;
	int	pos_point;

	if (argc != 2)
		return (error_msg(ERROR_ARG_NUM), false);
	size = ft_strlen(argv[1]);
	pos_point = size - 4;
	if (ft_strncmp(argv[1] + pos_point, ".rt", 4) != 0)
		return (error_msg(ERROR_ARG_FORMAT), false);
	return (true);
}

int	setup_data(t_data *data, int argc, char **argv)
{
	int	fd;

	if (is_valid_arg(argc, argv) == false)
		exit(EXIT_FAILURE);
	fd = open(argv[2], O_RDONLY);
	if (fd < 0)
		return (perror("open"), exit(EXIT_FAILURE), EXIT_FAILURE);
}

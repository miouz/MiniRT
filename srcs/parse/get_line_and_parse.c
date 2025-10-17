#include "../includes/minirt.h"

/**
 * @brief parse each line in .rt file to setup data:
 * for ambient_light, camera and spot_light it writes directly on struct data,
 * for geometries, it adds to linked list obj since object_counts not defined.
 *
 * @param line malloc'd single line in file
 * @param data address to data structure
 * @param obj address of the linked list's cursor to 
 * always point to the last node of list.
 * @param obj_count array of object_counts:
 * [0]ambient_light, [1]camera, [2]spot_light
 * @return EXIT_FAILURE if format error or EXIT_SUCCESS to continue
 * @warning the function DO NOT free the line DO NOT exit neither
 */
static int	parse_line_in_file(char *line, t_data *data,
			t_list **obj, int *obj_count)
{
	if (ft_strncmp(line, "A", 1) == 0)
		return (obj_count[0]++, parse_ambient_light(line + 1, data));
	if (ft_strncmp(line, "C", 1) == 0)
		return (obj_count[1]++, parse_camera(line + 1, data));
	if (ft_strncmp(line, "L", 1) == 0)
		return (obj_count[2]++, parse_light(line + 1, data));
	if (ft_strncmp(line, "sp", 2) == 0)
		return (parse_geometry(line + 2, &parse_sphere, obj, data));
	if (ft_strncmp(line, "pl", 2) == 0)
		return (parse_geometry(line + 2, &parse_plane, obj, data));
	if (ft_strncmp(line, "cy", 2) == 0)
		return (parse_geometry(line + 2, &parse_cylinder, obj, data));
	return (error_msg(ERROR_SCENE_FILE), EXIT_FAILURE);
}

int	get_line_and_parse(int fd, t_data *data, t_list *obj, int *obj_count)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (EXIT_SUCCESS);
		if (no_info_in_rest_of_line(line) == false
			&& parse_line_in_file(line, data, &obj, obj_count)
			== EXIT_FAILURE)
			return (free(line), EXIT_FAILURE);
		free(line);
		line = NULL;
	}
}

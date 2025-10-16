/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:42:45 by mzhou             #+#    #+#             */
/*   Updated: 2025/10/01 13:42:45 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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

/**
 * @brief parse each line in .rt file to setup data
 *
 * @param line malloc'd single line in file
 * @param data address to data structure
 * @return EXIT_FAILURE if format error or EXIT_SUCCESS to continue
 * @warning the function DO NOT free the line DO NOT exit neither
 */
static int	parse_line_in_file(char *line, t_data *data)
{
	if (ft_strncmp(line, "A", 1) == 0)
		return (parse_ambient_light(line + 1, data));
	if (ft_strncmp(line, "C", 1) == 0)
		return (parse_camera(line + 1, data));
	if (ft_strncmp(line, "L", 1) == 0)
		return (parse_spot_light(line + 1, data));
	if (ft_strncmp(line, "sp", 2) == 0)
		return (parse_sphere(line + 2, data));
	if (ft_strncmp(line, "pl", 2) == 0)
		return (parse_plane(line + 2, data));
	if (ft_strncmp(line, "cy", 2) == 0)
		return (parse_cylinder(line + 2, data));
	return (error_msg(ERROR_SCENE_FILE), EXIT_FAILURE);
}

/**
 * @brief setup data structure from argv
 *
 * @param data address to data structure
 * @param argc argc from program
 * @param argv address to argv from program
 * @return EXIT_SUCCESS or EXIT from function in case of error
 * @warning this function EXIT in case of error
 */
int	setup_data(t_data *data, int argc, char **argv)
{
	int		fd;
	char	*line;

	if (is_valid_arg(argc, argv) == false)
		exit(EXIT_FAILURE);
	fd = open(argv[2], O_RDONLY);
	if (fd < 0)
		return (perror("open"), exit(EXIT_FAILURE), EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL
			|| (line && line[0] != '\0'
				&& parse_line_in_file(line, data) == EXIT_FAILURE))
			return (free(line), line = NULL, exit(EXIT_FAILURE), EXIT_FAILURE);
		free(line);
		line = NULL;
	}
	//check if the right scene object number;
	if (data_is_valid(data) == false)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

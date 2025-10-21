#include "../includes/minirt.h"

int	append_str_to_line(char *buffer, char **line, int size)
{
	char	*new_line;	
	int		line_size;

	line_size = ft_strlen(*line);
	new_line = malloc(line_size + size + 1);
	if (new_line == NULL)
		return (EXIT_FAILURE);
	ft_memcpy(new_line, *line, line_size);
	ft_memcpy(new_line + line_size, buffer, size);
	new_line[line_size + size] = '\0';
	free(*line);
	*line = new_line;
	ft_memcpy(buffer, buffer + size, BUFFER_SIZE - size + 1);
	return (EXIT_SUCCESS);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	char		*pos;

	line = NULL;
	buffer[BUFFER_SIZE] = '\0';
	if (fd < 0 || fd > 1023)
		return (NULL);
	bytes_read = 0;
	pos = ft_memchr(buffer, '\n', BUFFER_SIZE);
	while (pos == NULL)
	{
		append_str_to_line(buffer, &line, BUFFER_SIZE);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(line), NULL);
		pos = ft_memchr(buffer, '\n', BUFFER_SIZE);
	}
	append_str_to_line(buffer, &line, pos - buffer + 1);
	return (line);
}

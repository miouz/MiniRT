/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:18:38 by mzhou             #+#    #+#             */
/*   Updated: 2025/01/15 08:45:21 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static char	*fill_buffer(int fd, t_dat *b)
{
	ssize_t	read_size;

	ft_memset(b->bu, '\0', BUFFER_SIZE);
	read_size = read(fd, b->bu, BUFFER_SIZE);
	if (read_size == -1)
		return (NULL);
	b->r = read_size;
	b->i = 0;
	if (read_size == 0)
		return (NULL);
	return (b->bu);
}

static char	*new_line(int fd, t_dat *b, char	*line)
{
	size_t	n;
	char	*slash_n;

	n = 0;
	slash_n = (char *)ft_memchr((char *)&(b->bu[b->i]), '\n', b->r - b->i);
	while (slash_n == NULL && b->i < b->r)
	{
		line = ft_str_n_join(line, &(b->bu[b->i]), b->r - b->i);
		if (line == NULL)
			return (NULL);
		b->i = b->r;
		if (b->r == BUFFER_SIZE)
		{
			if (fill_buffer(fd, b) == NULL)
				return (line);
			slash_n = (char *)ft_memchr(&(b->bu[b->i]), '\n', b->r - b->i);
		}
	}
	if (slash_n != NULL)
	{
		n = slash_n - &(b->bu[b->i]) + 1;
		line = ft_str_n_join(line, &(b->bu[b->i]), n);
		b->i = slash_n - b->bu + 1;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_dat	b;
	char			*line;
	char			*fill_return;

	if (fd < 0 || fd > 1023 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (b.i = 0, NULL);
	line = malloc(1 * sizeof (char));
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	if (b.i == 0 || b.i > b.r - 1)
	{
		fill_return = fill_buffer(fd, &b);
		if (fill_return == NULL)
			return (free(line), NULL);
	}
	if (b.i <= b.r - 1)
		line = new_line(fd, &b, line);
	if (line == NULL || (line != NULL && line[0] == '\0'))
		return (free(line), line = NULL, NULL);
	return (line);
}

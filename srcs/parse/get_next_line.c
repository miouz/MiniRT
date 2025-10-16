/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:18:38 by mzhou             #+#    #+#             */
/*   Updated: 2025/03/19 13:12:59 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

char	*ft_str_n_join(char *s1, char *s2, size_t n)
{
	size_t	i;
	char	*new;
	size_t	l;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1);
	new = malloc((l + n + 1) * sizeof(char));
	if (new == NULL)
		return (free((char *)s1), s1 = NULL, NULL);
	while (i < l)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		new[l + i] = s2[i];
		i++;
	}
	new[l + i] = '\0';
	return (free((char *)s1), s1 = NULL, new);
}

static char	*fill_buffer(int fd, t_dat *b)
{
	ssize_t	read_size;

	if (b->bu == NULL)
		b->bu = malloc(BUFFER_SIZE);
	if (b->bu == NULL)
		return (NULL);
	read_size = read(fd, b->bu, BUFFER_SIZE);
	if (read_size == -1)
		return (free(b->bu), b->bu = NULL, NULL);
	b->r = read_size;
	b->i = 0;
	if (read_size == 0)
		return (free(b->bu), b->bu = NULL, NULL);
	return (b->bu);
}

static char	*creat_new_line(int fd, t_dat *b, char	*line)
{
	size_t	n;
	char	*slash_n;

	n = 0;
	slash_n = (char *)ft_memchr(&(b->bu[b->i]), '\n', b->r - b->i);
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
	static t_dat	b[1024];
	char			*line;
	char			*fill_return;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (b[fd].i = 0, NULL);
	line = malloc(1 * sizeof (char));
	if (line == NULL)
		return (free(b[fd].bu), b[fd].bu = NULL, NULL);
	line[0] = '\0';
	if (b[fd].i == 0 || b[fd].i > b[fd].r - 1)
	{
		fill_return = fill_buffer(fd, &b[fd]);
		if (fill_return == NULL)
			return (free(line), NULL);
	}
	if (b[fd].i <= b[fd].r - 1)
		line = creat_new_line(fd, &b[fd], line);
	if (b[fd].i == b[fd].r)
		return (free(b[fd].bu), b[fd].bu = NULL, line);
	if (line == NULL || (line != NULL && line[0] == '\0'))
		return (free(line), line = NULL, free(b[fd].bu), b[fd].bu = NULL, NULL);
	return (line);
}

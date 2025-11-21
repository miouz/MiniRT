/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:06:23 by mzhou             #+#    #+#             */
/*   Updated: 2025/01/13 10:19:08 by mzhou            ###   ########.fr       */
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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = (unsigned char) c;
		ptr++;
		n--;
	}
	return (s);
}

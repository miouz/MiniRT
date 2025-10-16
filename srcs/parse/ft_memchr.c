/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:38:47 by mzhou             #+#    #+#             */
/*   Updated: 2024/11/25 17:33:29 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
/*scans  the initial n bytes of the memory area pointed to by s for the
 first instance of c, c and s interpreted as unsigned char
returns NULL if c = '\0'*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((void *)s)[i]);
		i++;
	}
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>
test '\0','\0', 7 
int	main(void)
{
	char *str = "weshlol145,";
	//str[4] = '\0';
	char *ptr = ft_memchr('\0', '\0', 7);
	char *ptr1 = memchr('\0', '\0', 7);
	
	printf("%p\n", ptr);
	printf("%p\n",ptr1);
	return (0);
}*/

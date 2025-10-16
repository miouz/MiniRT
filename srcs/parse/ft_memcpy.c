/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:35:09 by mzhou             #+#    #+#             */
/*   Updated: 2024/11/25 18:57:03 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
/*copies n bytes from memory area src to memory area dest. Doesnt check overlap
Use memmove(3) if the memory areas do overlap.*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return ((void *)dest);
}

/*#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	//char *src = "caca";
	char dest[] = "w
	int	a;

	a = 0;
	ft_memcpy(((void*)0), ((void*)0), 4);
	memcpy(((void*)0), ((void*)0), 4);
	while(a < 11)
	{
		printf("%c", dest[a]);
		a++;
	}
	return (0);
}*/

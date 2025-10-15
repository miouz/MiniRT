/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:27:52 by mzhou             #+#    #+#             */
/*   Updated: 2024/11/25 17:15:39 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/*convert integer to string without consider overflow*/
static size_t	count(int n)
{
	size_t			i;
	unsigned int	a;

	i = 1;
	if (n < 0)
	{
		i++;
		a = n * -1;
	}
	else
		a = n;
	while (a > 9)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*a;
	unsigned int	b;
	size_t			k;

	k = count(n);
	a = NULL;
	a = malloc(sizeof(char) * (k + 1));
	if (a == NULL)
		return (NULL);
	if (n < 0)
		b = n * -1;
	else
		b = n;
	while (k >= 1)
	{
		a[k - 1] = (b % 10) + '0';
		b = b / 10;
		k--;
	}
	if (n < 0)
		a[0] = '-';
	a[count(n)] = '\0';
	return (a);
}

/*int	main(void)
{
//	int	a;
//	int	b;
//	int c;
//	int d;
	int e;

//	a = -9870;
//	b = 0;
//	c = 76;
//	d = 98;
	e = -2147483648;
//	printf("%s\n", ft_itoa(a));
//	printf("%s\n", ft_itoa(b));
//	printf("%s\n", ft_itoa(c));
//	printf("%s\n", ft_itoa(d));
	printf("%s\n", ft_itoa(e));
	return (0);
}*/

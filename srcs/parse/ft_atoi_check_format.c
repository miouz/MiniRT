// #include "../includes/minirt.h"
#include "parse.h"

int	swap_nul_and_atoi(int *result, char *str, char *end)
{
	char	nul;

	nul = '\0';
	ft_swap(end, &nul);
	*result = ft_atoi(str);
	ft_swap(end, &nul);
	return (EXIT_SUCCESS);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	i;
	int	p_or_n;

	nbr = 0;
	i = 0;
	p_or_n = 1;
	while (((nptr[i] >= 9) && (nptr[i] <= 13)) || nptr[i] == 32)
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			p_or_n = -1;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	return (nbr * p_or_n);
}

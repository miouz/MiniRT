// #include "../includes/minirt.h"
#include "parse.h"

/**
 * @brief swap end with \0 in order to use atoi
 *
 * @param result address of int to write value
 * @param str address of string's begin
 * @param end address of string's end
 * @return return result of ft_atoi_check_format
 */
int	swap_nul_and_atoi(int *result, char *str, char *end)
{
	char	nul;
	int		res_atoi;

	nul = '\0';
	ft_swap(end, &nul);
	res_atoi = ft_atoi_check_format(str, result);
	ft_swap(end, &nul);
	return (EXIT_SUCCESS);
}

/**
 * @brief atoi and check integer overflow
 *
 * @param str address of string
 * @param result address of integer to write value
 * @return EXIT_SUCCESS if good format and EXIT_FAILURE if bad format
 */
int	ft_atoi_check_format(char *str, int *result )
{
	char	*return_itoa;

	*result = ft_atoi(str);
	return_itoa = ft_itoa(*result);
	if (return_itoa == NULL)
		return (EXIT_FAILURE);
	if (ft_strncmp(str, return_itoa, ft_strlen(str)) == 0)
		return (free(return_itoa), EXIT_SUCCESS);
	return (free(return_itoa), EXIT_FAILURE);
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

// #include "../includes/minirt.h"
#include "parse.h"

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

static int	get_digit_count(char *str, int *count_int, int *count_frac)
{
	*count_int = 0;
	*count_frac = 0;
	while (str[*count_int] && ft_isdigit(str[*count_int]) == true)
	{
		(*count_int)++;
		if (str[*count_int] && str[*count_int] == '.')
		{
			if (ft_isdigit(str[*count_int + 1]) == false)
				return (false);
			while (str[*count_int + 1 + *count_frac]
				&& ft_isdigit(str[*count_int + 1 + *count_frac]) == true)
				(*count_frac)++;
		}
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief check if the format is good double format
 *
 * @param str address point to string
 * @param count_int address of double's integer part count
 * @param count_frac address of double's fractionnal part count 
 * @return true if good format, false if bad format
 * @example 0, 54, 65.0 are good, .8, 65. is bad
 * integer digit count <= 10 and fractionnal digit count <= 5 
 */
static bool	is_good_double_format(char *str, int *count_int, int *count_frac)
{
	int	index_end;

	if (is_negative_sign(*str) == true)
		str++;
	get_digit_count(str, count_int, count_frac);
	index_end = *count_int;
	if (*count_frac > 0)
		index_end = *count_int + *count_frac + 1;
	if ((str[index_end] == '\0' || is_white_space(str[index_end]) == true)
		&& *count_int <= MAX_DOUBLE_INT_COUNT && *count_int > 0
		&& *count_frac <= MAX_DOUBLE_FRAC_COUNT)
		return (true);
	return (false);
}

int	swap_nul_and_atoi(int *result, char *str, char *end)
{
	char	nul;

	nul = '\0';
	ft_swap(end, &nul);
	*result = ft_atoi(str);
	ft_swap(end, &nul);
	return (EXIT_SUCCESS);
}

/**
 * @brief covert string to a double and check if overflowed
 *
 * @param str address of string
 * @param result address of double to reference the result
 * @return return EXIT_FAILURE if format problem or overflowed.
 * return EXIT_SUCCESS if conversion succeed.
 * @example good format : 0, 0.0, 54.0
 * max digit 9(integer part) + 5(fractionnal part)
 * bad format: .8, 000.0,  */
int	ft_atod_check_format(char *str, double *result)
{
	int		result_int;
	int		result_fractional;
	int		count_int;
	int		count_frac;
	double	pos_or_neg;

	pos_or_neg = 1;
	if (is_good_double_format(str, &count_int, &count_frac) == true)
	{
		if (is_negative_sign(str[0]) == true)
		{
			str++;
			pos_or_neg = -1;
		}
		swap_nul_and_atoi(&result_int, str, &str[count_int]);
		if (count_frac > 0)
			swap_nul_and_atoi(&result_fractional, &str[count_int + 1],
				&str[count_int + 1 + count_frac]);
		*result = (double)result_int;
		if (count_frac > 0)
			*result += (double)(result_fractional / pow(10, count_frac));
		return (*result *= pos_or_neg, EXIT_SUCCESS);
	}
	printf("%s\n", ERROR_DOUBLE_FORMAT);
	return (EXIT_FAILURE);
}

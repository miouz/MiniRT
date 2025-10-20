/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_check_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:01:39 by mzhou             #+#    #+#             */
/*   Updated: 2025/10/20 10:50:13 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	get_digit_count(char *str, int *count_int, int *count_frac)
{
	if (count_int)
		*count_int = 0;
	if (count_frac)
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
	if ((str[index_end] == '\0' || is_white_space(str[index_end]) == true
			|| str[index_end] == ',')
		&& *count_int <= MAX_DOUBLE_INT_COUNT && *count_int > 0
		&& *count_frac <= MAX_DOUBLE_FRAC_COUNT)
		return (true);
	return (false);
}

/**
 * @brief swap end with \0 to get a string in order to use atod
 *
 * @param result address of the double to fill
 * @param str address of string's begin
 * @param end address of string's end
 * @return return result of ft_atod_check_format
 */
int	swap_nul_and_atod(double *result, char *str, char *end)
{
	char	nul;
	int		res_atod;

	nul = '\0';
	ft_swap(end, &nul);
	res_atod = ft_atod_check_format(str, result);
	ft_swap(end, &nul);
	return (res_atod);
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

#ifndef PARSE_H
# define PARSE_H

# define ERROR_ARG_NUM "Error: please run ./miniRT <file's name>\n"
# define ERROR_ARG_FORMAT "Error: file's name should terminate with .rt\n"
# define ERROR_DOUBLE_FORMAT "Error: need less than 9(int) + 5(frac) digits\n"

# define MAX_DOUBLE_INT_COUNT 9
# define MAX_DOUBLE_FRAC_COUNT 5
# define MAX_DOUBLE_INT 2000000
# define MAX_DOUBLE_FRAC 4000000

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

int	ft_atod_check_format(char *str, double *result);
bool	no_info_in_rest_of_line(char *str);
int		get_next_double_in_range(char **str, double *num,
			double min, double max);
bool	is_white_space(int c);
bool	ft_isdigit(int c);
bool	is_negative_sign(char c);
void	ft_swap(char *a, char *b);

#endif // !PARSE_H

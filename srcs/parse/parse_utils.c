// #include "../includes/minirt.h"
#include "parse.h"

bool	is_white_space(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (true);
	return (false);
}

bool	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (true);
	return (false);
}

bool	is_negative_sign(char c)
{
	if (c == '-')
		return (true);
	return (false);
}

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

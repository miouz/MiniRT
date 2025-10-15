#include "parse.h"


// int	main(int argc, char **argv)
// {
// 	double result;
//
// 	if (ft_atod_check_format(argv[1], &result) == EXIT_SUCCESS)
// 		printf("result is %f\n", result);
// 	return (EXIT_SUCCESS);
// }

int	main(int argc, char **argv)
{
	char *ptr = argv[1];
	// double num;
	// int	result;
	t_color colors;
	t_coordinates value;

	// printf("str before is %s\n", ptr);
	// if (get_next_double_in_range(&ptr, &num, 0.0, 1.0) == EXIT_SUCCESS)
	// {
	// 	printf("str after is %s\n", ptr);
	// 	printf("double number is %f\n", num);
	// }


	
	printf("str before is %s\n", ptr);
	// if (get_next_color(&ptr, &colors) == EXIT_SUCCESS)
	// {
	// 	printf("str after is %s\n", ptr);
	// 	printf("colors are %d, %d, %d\n", colors.red, colors.green, colors.blue);
	// }
	if (parse_ambient_light(&ptr, &value) == EXIT_SUCCESS)
	{
		printf("str after is %s\n", ptr);
		printf("t_coordinates are %f, %f, %f\n", value.x, value.y, value.z);
	}
	return (EXIT_SUCCESS);
}

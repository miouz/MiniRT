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
	// t_color colors;
	// t_coordinates value;
	t_data	data;

	if (parse_ambient_light(ptr, &data) == EXIT_SUCCESS)
	{
		printf("ambient_lighting format good\n");
		printf("ambient_lighting color is: %d, %d, %d\n", data.ambient_lighting.color.red,
		 	data.ambient_lighting.color.green, data.ambient_lighting.color.blue);
		printf("ambient_lighting intensity is: %f\n", data.ambient_lighting.intensity);
	}

	if (parse_camera(ptr, &data) == EXIT_SUCCESS)
	{
		printf("camera format good\n");
		printf("camera center is: %f, %f, %f\n", data.camera.center.x, data.camera.center.y, data.camera.center.z);
		printf("camera vector is: %f, %f, %f\n", data.camera.direction.x, data.camera.direction.y, data.camera.direction.z);
		printf("camera fov is: %d\n", data.camera.fov);
	}
	
	// printf("str before is %s\n", ptr);
	// if (get_next_double_in_range(&ptr, &num, 0.0, 1.0) == EXIT_SUCCESS)
	// {
	// 	printf("str after is %s\n", ptr);
	// 	printf("double number is %f\n", num);
	// }

	// if (get_next_color(&ptr, &colors) == EXIT_SUCCESS)
	// {
	// 	printf("str after is %s\n", ptr);
	// 	printf("colors are %d, %d, %d\n", colors.red, colors.green, colors.blue);
	// }
	
	// if (get_next_int_in_range(&ptr, &result, 0, 180) == EXIT_SUCCESS)
	// {
	// 	printf("str after is %s\n", ptr);
	// 	printf("int number is %d\n", result);
	// }

	// if (get_next_coordinates(&ptr, &value) == EXIT_SUCCESS)
	// {
	// 	printf("str after is %s\n", ptr);
	// 	printf("t_coordinates are %f, %f, %f\n", value.x, value.y, value.z);
	// }
	return (EXIT_SUCCESS);
}

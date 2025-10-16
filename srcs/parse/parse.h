/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:42:45 by mzhou             #+#    #+#             */
/*   Updated: 2025/10/01 13:42:45 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/*==============================ERROR_MSG===================================*/
# define ERROR_ARG_NUM "Error: please run ./miniRT <file's name>\n"
# define ERROR_ARG_FORMAT "Error: file's name should terminate with .rt\n"
# define ERROR_SCENE_FILE "Error: fail to generate scene with file\n"
# define ERROR_DOUBLE_FORMAT "Error: need less than 9(int) + 5(frac) digits\n"
# define ERROR_AML "Error: ambient light not correct\n"
# define ERROR_CAM "Error: camera not correct\n"
# define ERROR_LIGHT "Error: light not correct\n"
# define ERROR_SPHERE "Error: sphere not correct\n"
# define ERROR_PLANE "Error: plane not correct\n"
# define ERROR_CYLINDER "Error: cylinder not correct\n"
# define ERROR_NO_GEOMETRY "Error: no geometry in scene\n"
# define ERROR_NO_3_OBJ "Error: need 1 ambient light, 1 light and 1 camera\n"

/*==================================NUMBERS===========================*/
# define MAX_DOUBLE_INT_COUNT 9
# define MAX_DOUBLE_FRAC_COUNT 5
# define MAX_DOUBLE_INT 2000000
# define MAX_DOUBLE_FRAC 4000000
# define MAX_DOUBLE 9999999

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>

//get_next_line_structure
//bu = buffer, i = index, r = read_size
typedef struct s_dat
{
	char	*bu;
	size_t	i;
	size_t	r;
}	t_dat;

/*==================================PARSE_FUNC===========================*/
int		check_and_jump_spaces(char **line);
int		get_line_and_parse(int fd, t_data *data, t_list *obj, int *obj_count);
int		setup_data(t_data *data, int argc, char **argv);

/*==================================PARSE_OBJECTS===========================*/
int		parse_ambient_light(char *rest, t_data *data);
int		parse_camera(char *rest, t_data *data);
int		parse_light(char *rest, t_data *data);

/*==================================PARSE_GEOMETRY===========================*/
int		parse_geometry(char *rest,
			int *parse_func(char *, t_list *), t_list **last_obj, t_data *data);
int		parse_plane(char *rest, t_object *object);
int		parse_cylinder(char *rest, t_object *object);
int		parse_sphere(char *rest, t_object *object);

/*==================================GETTERS===========================*/
int		get_next_double_in_range(char **str, double *num,
			double min, double max);
int		get_next_coordinates(char **line, t_coordinates *value);
int		get_next_vector(char **line, t_coordinates *value);
int		get_next_int_in_range(char **line, int *result, int min, int max);
int		get_next_color(char **line, t_color *color);

/*==================================CHECKERS===========================*/
bool	int_is_in_range(int value, int min, int max);
bool	double_is_in_range(double value, double min, double max);
bool	no_info_in_rest_of_line(char *str);
bool	is_white_space(int c);
bool	ft_isdigit(int c);
bool	is_negative_sign(char c);
bool	is_normalized_vector(t_coordinates vector);
bool	scene_is_valid(t_data *data, int *obj_count);
bool	is_valid_arg(int argc, char **argv);


/*==================================UTILS===========================*/
int		ft_atod_check_format(char *str, double *result);
int		ft_atoi_check_format(char *str, int *result );
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		swap_nul_and_atod(double *result, char *str, char *end);
int		swap_nul_and_atoi(int *result, char *str, char *end);
void	ft_swap(char *a, char *b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_list	*ft_lstnew(void *content);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);
void	*ft_memchr(const void *s, int c, size_t n);

#endif // !PARSE_H

#include "../includes/minirt.h"

int	parse_sphere(char *rest, t_object *object)
{
	if (!object)
		return (EXIT_FAILURE);
	object->type = SPHERE;
	if (get_next_coordinates(&rest, &object->data.sphere.center) == EXIT_SUCCESS
		&& get_next_double_in_range(&rest, &object->data.sphere.diameter,
			0, MAX_DOUBLE) == EXIT_SUCCESS
		&& get_next_color(&rest, &object->color) == EXIT_SUCCESS
		&& no_info_in_rest_of_line(rest) == true
		&& object->data.sphere.diameter != 0)
		return (EXIT_SUCCESS);
	return (error_msg(ERROR_SPHERE), EXIT_FAILURE);
}

int	parse_cylinder(char *rest, t_object *object)
{
	if (!object)
		return (EXIT_FAILURE);
	object->type = CYLINDER;
	if (get_next_coordinates(&rest,
			&object->data.cylinder.center) == EXIT_SUCCESS
		&& get_next_vector(&rest,
			&object->data.cylinder.axis_vector) == EXIT_SUCCESS
		&& get_next_double_in_range(&rest,
			&object->data.cylinder.diameter, 0, MAX_DOUBLE) == EXIT_SUCCESS
		&& get_next_double_in_range(&rest,
			&object->data.cylinder.height, 0, MAX_DOUBLE) == EXIT_SUCCESS
		&& get_next_color(&rest, &object->color) == EXIT_SUCCESS
		&& no_info_in_rest_of_line(rest) == true
		&& object->data.cylinder.diameter != 0
		&& object->data.cylinder.height != 0)
		return (EXIT_SUCCESS);
	return (error_msg(ERROR_CYLINDER), EXIT_FAILURE);
}

int	parse_plane(char *rest, t_object *object)
{
	if (!object)
		return (EXIT_FAILURE);
	object->type = PLANE;
	if (get_next_coordinates(&rest,
			&object->data.plane.point) == EXIT_SUCCESS
		&& get_next_vector(&rest,
			&object->data.plane.ortho_vector) == EXIT_SUCCESS
		&& get_next_color(&rest, &object->color) == EXIT_SUCCESS
		&& no_info_in_rest_of_line(rest) == true)
		return (EXIT_SUCCESS);
	return (error_msg(ERROR_PLANE), EXIT_FAILURE);
}

/**
 * @brief it malloc for content and node, add the new node to the list
 *
 * @param last_obj address of last_obj on the list
 * @return EXIT_FAILURE if malloc problem
 * @warning this function malloc but doesn't free locally!
 */
static int	creat_add_obj_to_lst(t_list *last_obj)
{
	t_list		*new;
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (object == NULL)
		return (perror("malloc"), EXIT_FAILURE);
	new = ft_lstnew(object);
	if (new == NULL)
		return (free(object), perror("malloc"), EXIT_FAILURE);
	last_obj->next = new;
	return (EXIT_SUCCESS);
}

/**
 * @brief parse the geometry, add to the object linked list and add object counts
 *
 * @param rest rest of string after identifier
 * @param parse_func address of function to use according to geometry type
 * @param last_obj address of last_obj's node on the linked list
 * @param data address of structure data
 * @return return EXIT_SUCCESS or EXIT_FAILURE
 * @warning this function update the linked list's cursor to the last object!
 */
int	parse_geometry(char *rest, int parse_func(char *, t_object *),
			t_list **last_obj, t_data *data)
{
	if (parse_func)
	{
		if (creat_add_obj_to_lst(*last_obj) == EXIT_SUCCESS
			&& parse_func(rest, (*last_obj)->next->content) == EXIT_SUCCESS)
		{
			data->nb_objects++;
			*last_obj = (*last_obj)->next;
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

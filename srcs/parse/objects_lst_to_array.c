#include "../includes/minirt.h"

int	obj_lst_to_array(t_list *lst, t_object *objects, int count)
{
	int	index;

	if (!lst)
		return (EXIT_FAILURE);
	objects = malloc(count * sizeof(t_object));
	if (objects == NULL)
		return (perror("malloc"), EXIT_FAILURE);
	index = 0;
	while (index < count)
	{
		if (ft_memcpy(&objects[index], lst->content, sizeof(t_object)))
			index++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

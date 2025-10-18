/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <mzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:42:45 by mzhou             #+#    #+#             */
/*   Updated: 2025/10/01 13:42:45 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	open_file_get_fd(int *fd, char *file_name)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
		return (perror("open"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	init_parse_data(t_data *data, int *obj_count)
{
	data->nb_objects = 0;
	data->objects = NULL;
	obj_count[0] = 0;
	obj_count[1] = 0;
	obj_count[2] = 0;
	return (EXIT_SUCCESS);
}

static int	obj_lst_to_array(t_list *lst, t_object **objects, int count)
{
	int	index;

	if (!lst)
		return (EXIT_FAILURE);
	*objects = malloc(count * sizeof(t_object));
	if (*objects == NULL)
		return (perror("malloc"), EXIT_FAILURE);
	index = 0;
	while (index < count)
	{
		if (ft_memcpy(&(*objects)[index], lst->content, sizeof(t_object)))
		{
			lst = lst->next;
			index++;
		}
		else
			return (free(*objects), *objects = NULL, EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	free_lst_and_exit(t_list **lst)
{
	ft_lstclear(lst, free);
	exit(EXIT_FAILURE);
}

/**
 * @brief setup data structure from argv
 *
 * @param data address to data structure
 * @param argc argc from program
 * @param argv address to argv from program
 * @return EXIT_SUCCESS or EXIT from function in case of error
 * @warning this function EXIT in case of error
 */
int	setup_data(t_data *data, int argc, char **argv)
{
	int		fd;
	t_list	*head;
	int		obj_count[3];

	head = NULL;
	if (is_valid_arg(argc, argv) == false
		|| open_file_get_fd(&fd, argv[1]) == EXIT_FAILURE
		|| init_parse_data(data, obj_count) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (get_line_and_parse(fd, data, &head, obj_count) == EXIT_FAILURE)
		free_lst_and_exit(&head);
	if (scene_is_valid(data, obj_count) == false)
		free_lst_and_exit(&head);
	if (obj_lst_to_array(head, &data->objects, data->nb_objects)
		== EXIT_FAILURE)
		free_lst_and_exit(&head);
	ft_lstclear(&head, free);
	return (EXIT_SUCCESS);
}

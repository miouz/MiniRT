/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:37:54 by mzhou             #+#    #+#             */
/*   Updated: 2025/01/30 10:38:15 by mzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!*lst || !lst || !del)
		return ;
	while (*lst)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		del(ptr->content);
		free(ptr);
		ptr = NULL;
	}
}

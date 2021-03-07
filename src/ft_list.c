/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:31:55 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/07 15:37:06 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lib_tools.h"

t_list	*list_new(void *content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

t_list	*list_add_new(void *content, t_list **list)
{
	t_list	*current;

	if (*list)
	{
		*list = list_new(content);
		return (*list);
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = list_new(content);
	if (!current->next)
	{
		delete_list(*list);
		return (0);
	}
}
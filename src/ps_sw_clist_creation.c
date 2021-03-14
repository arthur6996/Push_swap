/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sw_clist_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:35:16 by arthur            #+#    #+#             */
/*   Updated: 2021/03/14 09:55:34 by arthur           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//create a new elem of clist
t_clist *new_clist(int nbr)
{
	t_clist *new_elem;

	new_elem = malloc(sizeof(t_clist));
	if (!new_elem)
		return(0);
	new_elem->nbr = nbr;
	new_elem->next = 0;
	new_elem->prev = 0;
	new_elem->is_first = 0;
	return (new_elem);
}

//move new_elem at the top of the clist
void	add_at_top(t_clist **first_elem, t_clist *new_elem)
{
	t_clist *top;

	top = *first_elem;
	if (!top)
	{
		new_elem->next = new_elem;
		new_elem->prev = new_elem;
		new_elem->is_first = 1;
		*first_elem = new_elem;
		return ;
	}
	new_elem->next = top;
	new_elem->prev = top->prev;
	new_elem->is_first = 1;
	top->prev = new_elem;
	top->is_first = 0;
	*first_elem = new_elem;
}
// create a new elem and place it at the top of the list
// return the new elem pointer or 0 if error
t_clist	*create_add_top(int nbr, t_clist **first_elem)
{
	t_clist	*new_elem;

	new_elem = new_clist(nbr);
	if (!new_elem)
		return (0);
	add_at_top(first_elem, new_elem);
	return (new_elem);
}

int		size_clist(t_clist *st)
{
	int	i;

	if (!st->is_first)
		return (-1);
	if (!st)
		return (0);
	i = 1;
	st = st->next;
	while(!st->is_first)
	{
		i++;
		st = st->next;
	}
	return (i);
}
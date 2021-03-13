/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sw_clist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:35:16 by arthur            #+#    #+#             */
/*   Updated: 2021/03/13 11:47:53 by arthur           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	add_at_top(t_clist **first_elem, t_clist *new_elem)
{
	t_clist *top;

	top = *first_elem;
	new_elem->next = top;
	new_elem->prev = top->prev;
	new_elem->is_first = 1;
	top->prev = new_elem;
	top->is_first = 0;
	*first_elem = new_elem;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_s_and_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:37:31 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/07 15:24:29 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		sa(t_stack **a, t_stack **b)
{
	int		buffer;
	t_stack	*current_node;

	(void)b;
	current_node = *a;
	if (size_stack(current_node) < 2)
		return ;
	buffer = current_node->nbr;
	current_node->nbr = current_node->next->nbr;
	current_node->next->nbr = buffer;
}

void		sb(t_stack **a, t_stack **b)
{
	int		buffer;
	t_stack	*current_node;

	(void)a;
	current_node = *b;
	if (size_stack(current_node) < 2)
		return ;
	buffer = current_node->nbr;
	current_node->nbr = current_node->next->nbr;
	current_node->next->nbr = buffer;
}

void		ss(t_stack **a, t_stack **b)
{
	sa(a, b);
	sb(a, b);
}

void		pa(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (size_stack(*b) < 1)
		return ;
	node = *b;
	*b = (*b)->next;
	node->next = *a;
	*a = node;
}

void		pb(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (size_stack(*a) < 1)
		return ;
	node = *a;
	*a = (*a)->next;
	node->next = *b;
	*b = node;
}

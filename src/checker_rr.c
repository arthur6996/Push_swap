/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:48:48 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/08 11:22:59 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*prev;

	(void)b;
	if (size_stack(*a) < 2)
		return;
	current = *a;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = 0;
	current->next = *a;
	*a = current;
}

void	rrb(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*prev;

	(void)a;
	if (size_stack(*b) < 2)
		return;
	current = *b;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = 0;
	current->next = *b;
	*b = current;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a,b);
	rrb(a,b);
}
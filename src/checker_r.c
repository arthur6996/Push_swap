/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:43:30 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/08 12:49:11 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack **a, t_stack **b)
{
	t_stack	*buffer;
	t_stack	*content;

	(void)b;
	if (size_stack(*a) < 2)
		return ;
	buffer = *a;
	*a = buffer->next;
	content = *a;
	while (content->next)
		content = content->next;
	content->next = buffer;
	buffer->next = 0;
}

void	rb(t_stack **a, t_stack **b)
{
	t_stack	*buffer;
	t_stack	*content;

	(void)a;
	if (size_stack(*b) < 2)
		return ;
	buffer = *b;
	*b = buffer->next;
	buffer->next = 0;
	content = *b;
	while (content->next)
		content = content->next;
	content->next = buffer;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a,b);
	rb(a,b);
}
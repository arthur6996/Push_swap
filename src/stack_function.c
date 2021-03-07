/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:29:08 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/07 14:10:37 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "lib_tools.h"

t_stack		*create_stack_node(int nbr)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!new_elem)
		return (0);
	new_elem->nbr = nbr;
	new_elem->next = 0;
	return (new_elem);
}

void	destroy_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

t_stack	*create_stack(int argc, char **argv)
{
	int		i;
	t_stack	*first_node;
	t_stack	*current_node;

	first_node = create_stack_node(ft_atoi(argv[1]));
	if (!first_node)
		return (0);
	i = 2;
	current_node = first_node;
	while (i < argc)
	{
		current_node->next = create_stack_node(ft_atoi(argv[i]));
		if (!current_node->next)
		{
			destroy_stack(first_node);
			exit (error());
		}
		current_node = current_node->next;
		i++;
	}
	return (first_node);
}

void	read_stack(t_stack *stack)
{
	if (!stack)
		return;
	printf("%d", stack->nbr);
	stack = stack->next;
	while (stack)
	{
		printf(" %d", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}

unsigned int	size_stack(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
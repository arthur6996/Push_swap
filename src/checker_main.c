/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:37:52 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/07 14:15:28 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lib_tools.h"
#include "checker.h"

static int	check_args(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!is_int(argv[i]))
			exit (error());
		i++;
	}
	return (1);
}

int		error(void)
{
	ft_fdpustr("Error\n", 2);
	return (1);
}

static int	check_duplicata(t_stack *stack_a)
{
	t_stack	*current_stack;
	int		stack_nbr;

	while (stack_a)
	{
		stack_nbr = stack_a->nbr;
		current_stack = stack_a->next;
		while (current_stack)
		{
			if (current_stack->nbr == stack_nbr)
				return (0);
			current_stack = current_stack->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

int			is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->nbr > stack_a->next->nbr)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	check_args(argc, argv);
	stack_a = create_stack(argc, argv);
	//! read_stack(stack_a);
	if (!check_duplicata(stack_a))
		return (error());
	stack_b = 0;
	if (!read_exec_instr(&stack_a, &stack_b))
		return (error());
	if (is_sorted(stack_a, stack_b))
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}
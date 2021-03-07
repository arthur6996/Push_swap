/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:37:52 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/07 15:42:30 by abourbou         ###   ########lyon.fr   */
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
			exit (error(0, 0));
		i++;
	}
	return (1);
}

int		error(t_stack *a, t_stack *b)
{
	if (a)
		destroy_stack(a);
	if (b)
		destroy_stack(b);
	ft_fdpustr("Error\n", 2);
	return (1);
}

static int	check_duplicata(t_stack *a)
{
	t_stack	*current_stack;
	int		stack_nbr;

	while (a)
	{
		stack_nbr = a->nbr;
		current_stack = a->next;
		while (current_stack)
		{
			if (current_stack->nbr == stack_nbr)
				return (1);
			current_stack = current_stack->next;
		}
		a = a->next;
	}
	return (0);
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
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	check_args(argc, argv);
	a = create_stack(argc, argv);
	b = 0;
	if (check_duplicata(a))
		return (error(a, b));
	if (read_exec_instr(&a, &b))
		return (error(a, b));
	//!read_stack(b);
	if (is_sorted(a, b))
		printf("OK\n");
	else
		printf("KO\n");
	destroy_stack(a);
	destroy_stack(b);
	return (0);
}
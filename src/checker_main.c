/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:37:52 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/06 22:18:45 by abourbou         ###   ########lyon.fr   */
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
			return (0);
		i++;
	}
	return (1);
}

int		*fill_stack(int argc, char **argv)
{
	int	*stack_a;

	stack_a = malloc(sizeof(int) * argc);
}

int		main(int argc, char **argv)
{
	int		*stack_a;

	if (argc == 1)
		return (0);
	if (!check_args(argc, argv))
	{
		ft_fdpustr("Error\n", 2);
		return (1);
	}
	stack_a = fill_stack(argc, argv);
	return (0);
}
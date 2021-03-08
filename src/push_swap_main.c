/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:28:31 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/08 15:50:09 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lib_tools.h"
#include "push_swap.h"

static int	error(int *a)
{
	if (a)
		free(a);
	ft_fdpustr("Error\n", 2);
	return (1);
}

static int	*create_stack(int argc, char **argv)
{
	int	i;
	int	*a;

	a = malloc(sizeof(int) * (argc - 1));
	if (!a)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_int(argv[i]))
		{
			free(a);
			return (0);
		}
		a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (a);
}

static int	check_duplicata(int *a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	while(i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (a[j] == a[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int	*a;
	int	size_a;

	if (argc < 3)
		return (0);
	size_a = argc - 1;
	a = create_stack(argc, argv);
	if (!a)
		return (error(0));
	if (check_duplicata(a, size_a))
		return (error(a));
	return (0);
}
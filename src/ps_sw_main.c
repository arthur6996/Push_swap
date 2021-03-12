/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:28:31 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/08 16:35:12 by abourbou         ###   ########lyon.fr   */
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

int		rpl_easy_value(int **pa, const int size_a, const int *const_a)
{
	int	*cpy;
	int	i;
	int	j;

	cpy = malloc(sizeof(int) * size_a);
	if (!cpy)
		return (1);
	i = 0;
	while(i < size_a)
	{
		j = 0;
		cpy[i] = 0;
		while (j < size_a)
		{
			if (i != j && const_a[j] < const_a[i])
				cpy[i]++;
			j++;
		}
		i++;
	}
	free(*pa);
	*pa = cpy;
	return (0);
}

static int	valid_args(int argc, char **argv, int **pa)
{
	int	*a;
	int	size_a;

	size_a = argc - 1;
	a = create_stack(argc, argv);
	if (!a)
		return (error(0));
	if (check_duplicata(a, size_a))
		return (error(a));
	if (rpl_easy_value(&a, size_a, a))
		return (error(a));
	*pa = a;
	return (0);
}

//TODO change algorithm of rpl_easy_value
int		main(int argc, char **argv)
{
	int	*a;

	if (argc < 3)
		return (0);
	if (valid_args(argc, argv, &a))
		return(1);
	//sort_stack_alg(a);
	free(a);
	return (0);
}
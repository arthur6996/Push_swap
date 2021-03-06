/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:37:52 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/06 21:30:45 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lib_tools.h"

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

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("EMPTY LIST\nOK\n");
		return (0);
	}
	if (!check_args(argc, argv))
	{
		ft_fdpustr("Error\n", 2);
		return (1);
	}
	return (0);
}
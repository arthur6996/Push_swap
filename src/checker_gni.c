/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:24:26 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/08 10:45:25 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	int	free_and_ret(char **buffer)
{
	free(*buffer);
	*buffer = 0;
	return (-1);
}

static int	useless_read(char **buffer)
{
	char	c;

	if (read(0, &c, 1) == -1)
		return (free_and_ret(buffer));
	while (c != '\n' && c != EOF)
	{
		if (read(0, &c, 1) == -1)
			return (free_and_ret(buffer));
	}
	if (c == EOF)
		return (0);
	return (1);
}

int		get_next_instr(char **buffer)
{
	int		i;
	char	c;

	*buffer = malloc(5 * sizeof(char));
	if (!*buffer)
		return (-1);
	i = 0;
	if (read(0, *buffer + i, 1) == -1)
		return(free_and_ret(buffer));
	while (*buffer[i] != '\n' && *buffer[i] != EOF && i < 4)
	{
		if (read(0, *buffer + i, 1) == -1);
			return (free_and_ret(buffer));
		i++;
	}
	*buffer[i + 1] = 0;
	if (*buffer[i] == EOF)
		return (0);
	if (*buffer[i] == '\n')
		return (1);
	return (useless_read(buffer));
}
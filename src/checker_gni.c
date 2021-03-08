/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:24:26 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/08 12:12:31 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	int	free_and_ret(char **buffer)
{
	free(*buffer);
	*buffer = 0;
	return (-1);
}

static	void	ft_memzero(char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}

static int	useless_read(char **str)
{
	char	c;

	if (read(0, &c, 1) == -1)
		return (free_and_ret(str));
	while (c != '\n' && c != EOF)
	{
		if (read(0, &c, 1) == -1)
			return (free_and_ret(str));
	}
	if (c == EOF)
		return (0);
	return (1);
}

static int		read5_line(char *buffer)
{
	int		i;
	int		val_read;
	char	c;

	i = 0;
	val_read = read(0, &c, 1);
	if (val_read <= 0)
		return(val_read);
	if (c != '\n')
		buffer[i] = c;
	while (i < 3 && c != '\n')
	{
		i++;
		val_read = read(0, &c, 1);
		if (val_read <= 0)
			return (val_read);
		if (c != '\n')
			buffer[i] = c;
	}
	if (c == '\n')
		return (1);
	return (-2);
}

int		get_next_instr(char **str)
{
	char	*buffer;
	int		val;

	*str = 0;
	buffer = malloc(5 * sizeof(char));
	if (!buffer)
		return (-1);
	ft_memzero(buffer, 5);
	val = read5_line(buffer);
	if (val == -1)
		return(free_and_ret(&buffer));
	*str = buffer;
	if (val >= 0)
		return (val);
	return (useless_read(str));
}
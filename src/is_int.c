/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:30:17 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/06 21:37:55 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lib_tools.h"

unsigned int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static bool	is_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != '-' && (str[i] > '9' || str[i] < '0'))
			return (0);
		else if (i != 0 && (str[i] > '9' || str[i] < '0'))
			return (0);
		++i;
	}
	return (1);
}

char	ft_strcmp(char *str1, char *str2)
{
	int		i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

//return 1 if it is an int, else return 0
bool		is_int(char *str)
{
	int	size;

	if (!is_nbr(str))
		return (0);
	size = 0;
	if (str[0] == '-')
		size--;
	size += ft_strlen(str);
	if (size > 10 || !size)
		return (0);
	if (size == 10)
	{
		if (str[0] == '-')
		{
			if (ft_strcmp(str, "-2147483647") > 0)
				return (0);
		}
		else if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	}
	return (1);
}
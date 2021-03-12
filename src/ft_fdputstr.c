/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdputstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:17:07 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/08 16:06:20 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_fdpustr(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

void	ft_memcpy(char *dest, const char *src, const int size)
{
	int		i;

	i = 0;
	while(i < size)
	{
		dest[i] = src[i];
		i++;
	}
}
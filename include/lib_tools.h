/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:32:04 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/07 10:42:25 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_TOOLS_H
# define LIB_TOOLS_H

typedef int bool;

unsigned int	ft_strlen(char *str);
bool	is_int(char *str);
char	ft_strcmp(char *str1, char *str2);
void	ft_fdpustr(char *str, int fd);
int		ft_atoi(char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:32:04 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/13 10:45:03 by arthur           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_TOOLS_H
# define LIB_TOOLS_H

#include <unistd.h>
#include <stdlib.h>

typedef int bool;
typedef struct	s_list
{
	void		*content;
	struct s_list	*next;
}				t_list;

//LIST
t_list	*list_new(void *content);
t_list	*list_add_new(void *content, t_list **list);
void	delete_list(t_list *list);

//TOOLS
unsigned int	ft_strlen(char *str);
bool	is_int(char *str);
char	ft_strcmp(char *str1, char *str2);
void	ft_fdpustr(char *str, int fd);
void	ft_memcpy(char *dest, const char *src, const int size);
void	ft_memset(char *dest, const char car, const int size);
int		ft_atoi(char *str);

#endif
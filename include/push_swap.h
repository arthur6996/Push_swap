/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:03:41 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/13 11:48:14 by arthur           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_clist
{
	int				nbr;
	struct s_list	*next;
	struct s_list	*prev;
	int				is_first;
}				t_clist;

//algo
void    yt_algo(int *a, int *b);

//circular list functions
t_clist	*new_clist(int nbr);
void	add_at_top(t_clist **first_elem, t_clist *new_elem);
t_clist	*get_n_elem(int n);
#endif
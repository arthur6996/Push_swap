/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sw_clist_operation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 09:45:06 by arthur            #+#    #+#             */
/*   Updated: 2021/03/14 10:23:23 by arthur           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    st_swap(t_clist *a, t_clist *b, char name)
{
    int buffer;

    if (size_clist(a) > 1)
    {
        buffer = a->nbr;
        a->nbr = a->next->nbr;
        a->next->nbr = buffer;
    }
    if (size_clist(b) > 1)
    {
        buffer = b->nbr;
        b->nbr = b->next->nbr;
        b->next->nbr = buffer;
    }
    printf("s%c\n", name);
}

//put first elem of origin into dest
void    st_push(t_clist **dest, t_clist **origin, char name)
{
    t_clist *buffer;

    if (size_clist(*origin) > 0)
    {
        buffer = *origin;
        *origin = (*origin)->next;
        (*origin)->prev = buffer->prev;
        (*origin)->is_first = 1;
        buffer->next = *dest;
        buffer->prev = (*dest)->prev;
        buffer->is_first = 1;
        (*dest)->prev = buffer;
        (*dest)->is_first = 0;
        *dest = buffer;
    }
    printf("p%c\n", name);
}

void    st_rotate(t_clist **a, t_clist **b, char name)
{
    if (size_clist(*a) > 1)
    {
        (*a)->is_first = 0;
        *a = (*a)->next;
        (*a)->is_first = 1;
    }
    if (size_clist(*b) > 1)
    {
        (*b)->is_first = 0;
        *b = (*b)->next;
        (*b)->is_first = 1;
    }
    printf("r%c\n", name);
}

void    st_rev_rotate(t_clist **a, t_clist **b, char name)
{
    if (size_clist(*a) > 1)
    {
        (*a)->is_first = 0;
        *a = (*a)->prev;
        (*a)->is_first = 1;
    }
    if (size_clist(*b) > 1)
    {
        (*b)->is_first = 0;
        *b = (*b)->prev;
        (*b)->is_first = 1;
    }
    printf("rr%c\n", name);
}
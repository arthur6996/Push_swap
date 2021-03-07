/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_exec_instr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:33:48 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/07 14:19:53 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "lib_tools.h"

static t_dictionary	init_operations(t_dictionary *operations)
{
	operations[0].key = "sa";
	operations[1].key = "sb";
	operations[2].key = "ss";
	operations[3].key = "pa";
	operations[4].key = "pb";
	operations[5].key = "ra";
	operations[6].key = "rb";
	operations[7].key = "rr";
	operations[8].key = "rra";
	operations[9].key = "rrb";
	operations[10].key = "rrr";
}

int		read_exec_instr(t_stack **stack_a, t_stack **stack_b)
{
	static t_dictionary operations[11];
	init_operations(&operations[0]);

	return (0);
}
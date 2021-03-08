/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rx_instr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:33:48 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/08 12:53:41 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "lib_tools.h"

static void	init_operations(t_dictionary *operations)
{
	operations[0].key = "sa";
	operations[0].value = sa;
	operations[1].key = "sb";
	operations[1].value = sb;
	operations[2].key = "ss";
	operations[2].value = ss;
	operations[3].key = "pa";
	operations[3].value = pa;
	operations[4].key = "pb";
	operations[4].value = pb;
	operations[5].key = "ra";
	operations[5].value = ra;
	operations[6].key = "rb";
	operations[6].value = rb;
	operations[7].key = "rr";
	operations[7].value = rr;
	operations[8].key = "rra";
	operations[8].value = rra;
	operations[9].key = "rrb";
	operations[9].value = rrb;
	operations[10].key = "rrr";
	operations[10].value = rrr;
}

int		exec_instr(char *instruction, t_stack **a, t_stack **b)
{
	int		i;
	static int	first_one = 1;
	static t_dictionary	operations[11];

	if (first_one)
	{
		init_operations(&operations[0]);
		first_one = 0;
	}
	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(operations[i].key, instruction))
		{
			operations[i].value(a, b);
			return (1);
		}
		i++;
	}
	return (0);
}

int		read_instr(t_list **instructions)
{
	int		ret_value;
	char	*buffer;
	ret_value = get_next_instr(&buffer);
	while (ret_value > 0)
	{
		if (!list_add_new(buffer, instructions))
		{
			delete_list(*instructions);
			return (1);
		}
		ret_value = get_next_instr(&buffer);
	}
	if (ret_value == -1)
		delete_list(*instructions);
	return (ret_value);
}

int		read_exec_instr(t_stack **a, t_stack **b)
{
	t_list	*instructions;
	t_list	*instr;

	instructions = 0;
	if (read_instr(&instructions))
		return (1);
	instr = instructions;
	while (instr)
	{
		if (!exec_instr(instr->content, a, b))
		{
			delete_list(instructions);
			return (1);
		}
		instr = instr->next;
	}
	delete_list(instructions);
	return (0);
}
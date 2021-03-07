/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rx_instr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:33:48 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/07 15:56:30 by abourbou         ###   ########lyon.fr   */
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
	operations[6].key = "rb";
	operations[7].key = "rr";
	operations[8].key = "rra";
	operations[9].key = "rrb";
	operations[10].key = "rrr";
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
	(void)instructions;
	//TODO utilise get_next_line pour avoir les instructions utilisateurs
	//TODO gerer erreurs malloc
	//TODO gerer fin d'instructions
}

int		read_exec_instr(t_stack **a, t_stack **b)
{
	t_list	*instructions;
	t_list	*instr;

	if (read_instructions(&instructions))
	{
		delete_list(instructions);
		return (1);
	}
	instr = instructions;
	while (instr)
	{
		if (exec_instr(instr->content, a, b))
		{
			delete_list(instructions);
			return (1);
		}
		instr = instr->next;
	}
	delete_list(instructions);
	return (0);
}
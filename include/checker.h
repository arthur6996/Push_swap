/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:52:28 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/07 14:10:00 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	int				nbr;
	struct s_stack	*next;
}				t_stack;

typedef	void (*stack_function)(t_stack a, t_stack b);

typedef struct	s_dictionary
{
	char			*key;
	stack_function	value;
}				t_dictionary;

//STACK FUNCTIONS
t_stack		*create_stack_node(int nbr);
void		destroy_stack(t_stack	*stack);
t_stack		*create_stack(int argc, char **argv);
void		read_stack(t_stack *stack);
unsigned int	size_stack(t_stack *stack);

//MAIN FUNCTIONS
int			error(void);
int			read_exec_instr(t_stack **stack_a, t_stack **b);
int			is_sorted(t_stack *stack_a, t_stack *b);
#endif
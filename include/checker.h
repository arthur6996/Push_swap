/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:52:28 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/08 12:43:51 by abourbou         ###   ########lyon.fr   */
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

typedef	void (*stack_function)(t_stack **a, t_stack **b);

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
int			error(t_stack *a, t_stack *b);
int			read_exec_instr(t_stack **a, t_stack **b);
int			is_sorted(t_stack *a, t_stack *b);
int			get_next_instr(char **buffer);

//SMALL FUNCTIONS
int		exec_instr(char *instruction, t_stack **a, t_stack **b);

//INSTRUCTIONS FUNCTIONS
void	sa(t_stack **a, t_stack **b);
void	sb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **b);
void	rb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **b);
void	rrb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
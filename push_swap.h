/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:21:49 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/29 23:13:54 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // TODO delete
# include <unistd.h>
# include "lib/libft.h"

typedef struct s_node
{
	int				value;
	size_t			index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	size_t	size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

typedef enum e_bool
{
	FALSE	= 0,
	TRUE	= 1
}	t_bool;

typedef enum e_cmd_case
{
	SA		= 0,
	SB		= 1,
	SS		= 2,
	PA		= 3,
	PB		= 4,
	RA		= 5,
	RB		= 6,
	RR		= 7,
	RRA		= 8,
	RRB		= 9,
	RRR		= 10
}	t_cmd_case;

void	arg_validator(int argc, char **argv);
void	error_exitor(void);
void	init_stacks(t_stack *stack_a, t_stack *stack_b);
void	arg_parser(int argc, char **argv, t_stack *stack_a);

void	arg_indexer(t_stack *stack_a); // TODO delete
void	show_stack(t_stack *stack); // TODO delete
void	show_stack_top_bottom(t_stack *stack); // TODO delete
void	show_stack_top_bottom_info(t_stack *stack); // TODO delete

t_node	*new_node(int data);
t_node	*last_node(t_stack *stack);

void	cmd(t_cmd_case cmd, t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack_a, t_stack *stack_b, t_cmd_case cmd_case);
void	push(t_stack *stack_a, t_stack *stack_b, t_cmd_case cmd_case);
void	push_b_lowest(t_stack *stack_a, t_stack *stack_b);
void	push_b_second_lowest(t_stack *stack_a, t_stack *stack_b);

void	rotate(t_stack *stack_a, t_stack *stack_b, t_cmd_case cmd_case);
void	reverse_rotate(t_stack *stack_a, t_stack *stack_b, t_cmd_case cmd_case);

void	arrange_stack(t_stack *stack_a, t_stack *stack_b);
int		identifty_case(t_stack *stack_a);
void	arrange_under_5_args(t_stack *stack_a, t_stack *stack_b);
void	arrange_big_args(t_stack *stack_a, t_stack *stack_b);

#endif

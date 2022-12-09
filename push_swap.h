/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:21:49 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/10 02:33:44 by chanheki         ###   ########.fr       */
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

// TODO delete
// typedef enum e_stack_case
// {
// 	STACK_A	= 0,
// 	STACK_B	= 1
// }	t_stack_case;

typedef enum e_bool
{
	FALSE	= 0,
	TRUE	= 1
}	t_bool;

typedef enum e_order_case
{
	ASCENDING	= 0,
	DESCENDING	= 1,
}	t_order_case;

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

void	show_stack(t_stack *stack); // TODO delete
void	show_stack_top_bottom(t_stack *stack); // TODO delete
void	show_stack_top_bottom_info(t_stack *stack); // TODO delete
void	checker_argc_argv(int argc, char **argv); // TODO delete

t_node	*new_node(int data);
t_node	*pop(t_stack *stack);
void	clear_stack(t_stack *stack_a, t_stack *stack_b);

int		cmd(t_cmd_case cmd, t_stack *stack_a, t_stack *stack_b);
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

int		ft_pow(int a, int b);
int		is_sorted(t_stack *stack, size_t n);
void	sort_stack(t_stack *a, t_stack *b);
int		basis_merge(t_stack *a, t_stack *b);
int		basis_reverse_sort_b(t_stack *a, t_stack *b);
int		basis_sort_a(t_stack *a, t_stack *b);
int		basis_sort(t_stack *a, t_stack *b);
int		size_identifier(int a, int b, int c, t_order_case order);

void	arg_indexer(t_stack *stack_a);
void	a_to_b(t_stack *a, t_stack *b, int chunk, size_t i);
void	b_to_a(t_stack *a, t_stack *b);
void	sort_b(t_stack *a, t_stack *b, size_t length);

#endif

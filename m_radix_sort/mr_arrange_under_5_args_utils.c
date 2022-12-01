/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mr_arrange_under_5_args_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:48:12 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/02 03:07:43 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	identifty_case(t_stack *stack_a)
{
	t_node	*arg_1;
	t_node	*arg_2;
	t_node	*arg_3;

	arg_1 = stack_a->top;
	arg_2 = stack_a->top->next;
	arg_3 = stack_a->bottom;
	if (arg_2->index < arg_1->index && arg_1->index < arg_3->index)
		return (1);
	if (arg_3->index < arg_2->index && arg_2->index < arg_1->index)
		return (2);
	if (arg_2->index < arg_3->index && arg_3->index < arg_1->index)
		return (3);
	if (arg_1->index < arg_3->index && arg_3->index < arg_2->index)
		return (4);
	if (arg_3->index < arg_1->index && arg_1->index < arg_2->index)
		return (5);
	return (0);
}

void	push_b_lowest(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->bottom->index == 0)
	{
		cmd(RRA, stack_a, stack_b);
		cmd(PB, stack_a, stack_b);
	}
	else {
		while (stack_a->top)
		{
			if (stack_a->top->index == 0)
			{
				cmd(PB, stack_a, stack_b);
				break ;
			}
			cmd(RA, stack_a, stack_b);
		}	
	}
}

void	push_b_second_lowest(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top)
	{
		if (stack_a->top->index == 1)
		{
			cmd(PB, stack_a, stack_b);
			break ;
		}
		cmd(RA, stack_a, stack_b);
	}
}

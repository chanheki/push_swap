/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:22:11 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/24 04:04:10 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	_reverse_rotate(t_stack *stack)
{
	t_node *temp;
	
	if (stack->size <= 1)
		return (0);
	temp = stack->bottom->prev;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->top->prev;
	stack->bottom = temp;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
	return (1);
}

void	reverse_rotate(t_stack *stack_a, t_stack *stack_b, t_cmd_case cmd_case)
{
	if (cmd_case == RRA)
	{
		if (_reverse_rotate(stack_a))
			write(1, "rra\n", 4);
	}
	else if (cmd_case == RRB)
	{
		if (_reverse_rotate(stack_b))
			write(1, "rrb\n", 4);
	}
	else if (cmd_case == RRR)
	{
		_reverse_rotate(stack_a);
		_reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}

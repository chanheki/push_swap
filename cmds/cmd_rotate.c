/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:22:08 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/24 04:12:55 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

static int	_rotate(t_stack *stack)
{
	t_node *temp;
	
	if (stack->size <= 1)
		return (0);
	temp = stack->top->next;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->bottom = stack->bottom->next;
	stack->top = temp;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
	return (1);
}

void	rotate(t_stack *stack_a, t_stack *stack_b, t_cmd_case cmd_case)
{
	if (cmd_case == RA)
	{
		if (_rotate(stack_a))
			write(1, "ra\n", 3);
	}
	else if (cmd_case == RB)
	{
		if (_rotate(stack_b))
			write(1, "rb\n", 3);
	}
	else if (cmd_case == RR)
	{
		_rotate(stack_a);
		_rotate(stack_b);
		write(1, "rr\n", 3);
	}
}

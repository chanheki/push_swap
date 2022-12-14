/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:22:18 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/02 02:41:01 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_operator(t_stack *stack, t_node *temp)
{
	temp->prev = NULL;
	temp->next = stack->top;
	if (stack->top)
		stack->top->prev = temp;
	stack->top = temp;
	stack->size++;
	if (stack->size == 1)
		stack->bottom = temp;
}

static int	_push(t_stack *stack_push, t_stack *stack_pop)
{
	t_node	*temp;

	if (stack_pop->size == 0)
		return (0);
	temp = pop(stack_pop);
	push_operator(stack_push, temp);
	return (1);
}

void	push(t_stack *stack_a, t_stack *stack_b, t_cmd_case cmd_case)
{
	if (cmd_case == PA)
	{
		if (_push(stack_a, stack_b))
			write(1, "pa\n", 3);
	}
	else if (cmd_case == PB)
	{
		if (_push(stack_b, stack_a))
			write(1, "pb\n", 3);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:22:18 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/29 23:21:49 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_operator(t_stack *stack, t_node *temp)
{
	temp->prev = NULL;
	temp->next = stack->top;
	stack->top = temp;
	stack->size++;
	if (stack->size == 1)
		stack->bottom = temp;
}

static t_node	*pop(t_stack *stack)
{
	t_node	*ret_node;

	ret_node = stack->top;
	if (stack->size > 1)
		stack->top = stack->top->next;
	else
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	stack->size--;
	return (ret_node);
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

void	push(t_stack *stack_a, t_stack *stack_b, t_stack_case stack_case)
{
	if (stack_case == STACK_A)
	{
		if (_push(stack_a, stack_b))
			write(1, "pa\n", 3);
	}
	else if (stack_case == STACK_B)
	{
		if (_push(stack_b, stack_a))
			write(1, "pb\n", 3);
	}
}

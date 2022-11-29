/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:21:58 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/29 23:04:24 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	_swap(t_stack *stack)
{
	int	temp;

	if (stack->top == NULL || stack->top->next == NULL)
		return (0);
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
	return (1);
}

void	swap(t_stack *stack_a, t_stack *stack_b, t_stack_case stack_case)
{
	if (stack_case == STACK_A)
	{
		if (_swap(stack_a))
			write(1, "sa\n", 3);
	}
	else if (stack_case == STACK_B)
	{
		if (_swap(stack_b))
			write(1, "sb\n", 3);
	}
	else if (stack_case == STACK_BOTH)
	{
		if (_swap(stack_a) && _swap(stack_b))
			write(1, "ss\n", 3);
	}
}

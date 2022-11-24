/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:21:58 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/24 18:38:37 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap_(t_stack *stack)
{
	t_node	*curr_top;
	t_node	*next_top;
	t_node	*third_top;

	if (stack->top == NULL || stack->top->next == NULL)
		return (0);
	curr_top = stack->top;
	next_top = stack->top->next;
	third_top = stack->top->next->next;
	curr_top->prev = next_top;
	curr_top->next = third_top;
	next_top->prev = NULL;
	next_top->next = curr_top;
	stack->top = next_top;
	if (third_top)
		third_top->prev = curr_top;
	return (1);
}

void	swap(t_stack *stack_a, t_stack *stack_b, t_stack_case stack_case)
{
	if (stack_case == STACK_A)
	{
		if (swap_(stack_a))
			write(1, "sa\n", 3);
	}
	else if (stack_case == STACK_B)
	{
		if (swap_(stack_b))
			write(1, "sb\n", 3);
	}
	else if (stack_case == STACK_BOTH)
	{
		if (swap_(stack_a) && swap_(stack_b))
			write(1, "ss\n", 3);
	}
}

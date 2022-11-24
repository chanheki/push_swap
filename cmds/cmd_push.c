/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:22:18 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/24 06:17:07 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_operator(t_stack *stack, t_node *temp)
{
	temp->prev = NULL;
	temp->next = stack->top;
	stack->top = temp;
	stack->size++;
}

static t_node	*pop(t_stack *stack)
{
	t_node	*ret_node;

	if (stack->size == 0)
		return (NULL);
	ret_node = stack->top;
	if (stack->size >= 2)
		stack->top = stack->top->next;
	else
		stack->top = NULL;
	stack->size--;
	return (ret_node);
}

static void	push_(t_stack *stack_push, t_stack *stack_pop, t_stack_case sc)
{
	t_node	*temp;

	if (stack_pop->size == 0)
		return ;
	temp = pop(stack_pop);
	push_operator(stack_push, temp);
	if (sc == STACK_A)
		write(1, "pa\n", 3);
	if (sc == STACK_B)
		write(1, "pb\n", 3);
}

void	push(t_stack *stack_b, t_stack *stack_a, t_stack_case stack_case)
{
	if (stack_case == STACK_A)
		push_(stack_b, stack_a, stack_case);
	else if (stack_case == STACK_B)
		push_(stack_a, stack_b, stack_case);
}

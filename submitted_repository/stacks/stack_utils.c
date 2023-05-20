/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:23:28 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/13 23:30:50 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_b->size = 0;
	stack_b->top = NULL;
	stack_b->bottom = NULL;
}

t_node	*new_node(int data)
{
	t_node		*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_exitor();
	new_node->value = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = 0;
	return (new_node);
}

t_node	*pop(t_stack *stack)
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

void	clear_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	while (stack_b->size)
	{
		node = pop(stack_b);
		if (node)
			break ;
		free(node);
		node = NULL;
	}
	while (stack_a->size)
	{
		node = pop(stack_a);
		if (node)
			break ;
		free(node);
		node = NULL;
	}
}

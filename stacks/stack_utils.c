/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:23:28 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/29 23:18:12 by chanheki         ###   ########.fr       */
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
	static int	static_index = 0;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_exitor();
	new_node->value = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = static_index++;
	return (new_node);
}

//TODO show stack delete
void	show_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		printf("[index: %zu] %d \n", node->index, node->value);
		node = node->next;
	}
}

//TODO show top delete
void	show_stack_top_bottom(t_stack *stack)
{
	if (stack->top)
		printf("stack top: %d \n", stack->top->value);
	else
		printf("stack top: null \n");
	if (stack->bottom)
		printf("stack bottom: %d \n", stack->bottom->value);
	else
		printf("stack bottom: null \n");
}

//TODO show top_bottom info delete
void	show_stack_top_bottom_info(t_stack *stack)
{
	if (stack->top)
		printf("stack top NEXT: %d \n", stack->top->next->value);
	else
		printf("stack top: null \n");
	if (stack->bottom)
		printf("stack bottom PREV: %d \n", stack->bottom->prev->value);
	else
		printf("stack bottom: null \n");
}


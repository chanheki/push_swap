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

void	rotate_a(t_stack *stack_a, t_bool is_print)
{
	t_node	*temp;
	t_node	*temp_next;

	if (stack_a->size <= 1)
		return ;
	temp = stack_a->top;
	temp_next = stack_a->top->next;
	stack_a->bottom->next = temp;
	temp->prev = stack_a->bottom;
	temp->next = NULL;
	stack_a->bottom = temp;
	stack_a->top = temp_next;
	if (is_print == TRUE)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b, t_bool is_print)
{
	t_node	*temp_top;

	if (stack_b->size <= 1)
		return ;
	temp_top = stack_b->top;
	temp_top->prev = last_node(stack_b);
	temp_top->next = NULL;
	last_node(stack_b)->next = temp_top;
	stack_b->bottom = temp_top;
	stack_b->top = stack_b->top->next;
	stack_b->top->prev = NULL;
	stack_b->bottom->next = NULL;
	if (is_print == TRUE)
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1 || stack_a->size <= 1)
		return ;
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	write(1, "rr\n", 3);
}

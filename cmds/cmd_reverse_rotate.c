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

void	rotate_reverse_a(t_stack *stack_a, t_bool is_print)
{
	t_node	*temp_bottom;
	t_node	*temp_bottom_prev;

	if (stack_a->size <= 1)
		return ;
	temp_bottom = stack_a->bottom;
	temp_bottom_prev = stack_a->bottom->prev;
	temp_bottom->next = stack_a->top;
	temp_bottom->prev = NULL;
	stack_a->top = temp_bottom;
	stack_a->bottom = temp_bottom_prev;
	stack_a->bottom->next = NULL;
	if (is_print == TRUE)
		write(1, "rra\n", 4);
}

void	rotate_reverse_b(t_stack *stack_b, t_bool is_print)
{
	t_node	*temp_bottom;
	t_node	*temp_bottom_prev;

	if (stack_b->size <= 1)
		return ;
	temp_bottom = stack_b->bottom;
	temp_bottom_prev = stack_b->bottom->prev;
	temp_bottom->next = stack_b->top;
	temp_bottom->prev = NULL;
	stack_b->top = temp_bottom;
	stack_b->bottom = temp_bottom_prev;
	stack_b->bottom->next = NULL;
	if (is_print == TRUE)
		write(1, "rrb\n", 4);
}

void	rotate_reverse_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1 || stack_a->size <= 1)
		return ;
	rotate_reverse_a(stack_a, FALSE);
	rotate_reverse_b(stack_b, FALSE);
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:41:22 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/16 15:08:50 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack, size_t n)
{
	t_node	*node;

	node = stack->top;
	while (--n)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	basis_sort(t_stack *a, t_stack *b)
{
	size_t	i;

	if (a->size <= 3)
		basis_sort_a(a, b);
	else if (a->size <= 6)
	{
		i = a->size - 3;
		while (i--)
			cmd(PB, a, b);
		basis_sort_a(a, b);
		basis_reverse_sort_b(a, b);
		basis_merge(a, b);
	}
}

void	basis_sort_a(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			cmd(SA, a, b);
	}
	else if (a->size == 3)
	{
		if (size_identifier(a->top->value, a->top->next->value, \
								a->bottom->value, ASCENDING) == 1)
			cmd(RA, a, b);
		else if (size_identifier(a->top->value, a->top->next->value, \
								a->bottom->value, ASCENDING) == 2)
			cmd(RRA, a, b);
		if (a->top->value > a->top->next->value)
			cmd(SA, a, b);
	}
}

void	basis_reverse_sort_b(t_stack *a, t_stack *b)
{
	if (b->size == 2)
	{
		if (b->top->value < b->top->next->value)
			cmd(SB, a, b);
	}
	else if (b->size == 3)
	{
		if (size_identifier(b->top->value, b->top->next->value, \
								b->bottom->value, DESCENDING) == 1)
			cmd(RB, a, b);
		else if (size_identifier(b->top->value, b->top->next->value, \
								b->bottom->value, DESCENDING) == 2)
			cmd(RRB, a, b);
		if (b->top->value < b->top->next->value)
			cmd(SB, a, b);
	}
}

void	basis_merge(t_stack *a, t_stack *b)
{
	size_t	a_length;
	size_t	b_length;

	a_length = a->size;
	b_length = b->size;
	while (a_length + b_length)
	{
		if (b_length == 0)
			a_length -= cmd(RRA, a, b);
		else if (a_length == 0)
			b_length -= cmd(PA, a, b);
		else if (a->bottom->value > b->top->value)
			a_length -= cmd(RRA, a, b);
		else
			b_length -= cmd(PA, a, b);
	}
}

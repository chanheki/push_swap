/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:41:22 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/09 16:59:40 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack, size_t n)
{
	t_node	*node;

	if (n > stack->size)
		n = stack->size;
	node = stack->top;
	while (--n)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	basis_sort(t_stack *a, t_stack *b)
{
	size_t	i;

	if (a->size <= 3)
		return (basis_sort_a(a, b));
	else if (a->size <= 6)
	{
		i = a->size - 3;
		while (i--)
			cmd(PB, a, b);
		basis_sort_a(a, b);
		basis_reverse_sort_b(a, b);
		basis_merge(a, b);
		return (1);
	}
	else
		return (-1);
}

int	basis_sort_a(t_stack *a, t_stack *b)
{
	if (a->size <= 1)
		return (1);
	else if (a->size == 2)
		return (a->top->value < a->top->next->value || cmd(SA, a, b));
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
		return (1);
	}
	else
		return (0);
}

int	basis_reverse_sort_b(t_stack *a, t_stack *b)
{
	if (b->size <= 1)
		return (1);
	else if (b->size == 2)
		return (b->top->value > b->top->next->value || cmd(SB, a, b));
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
		return (1);
	}
	else
		return (0);
}

int	basis_merge(t_stack *a, t_stack *b)
{
	size_t	len[2];

	len[0] = a->size;
	len[1] = b->size;
	while (len[0] + len[1])
	{
		if (!len[1])
			len[0] -= cmd(RRA, a, b);
		else if (!len[0])
			len[1] -= cmd(PA, a, b);
		else if (a->bottom->value > b->top->value)
			len[0] -= cmd(RRA, a, b);
		else
			len[1] -= cmd(PA, a, b);
	}
	return (1);
}

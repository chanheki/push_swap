/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_progress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 00:50:09 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/13 23:47:15 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	get_top_index(t_stack *stack)
{
	return (stack->top->index);
}

void	a_to_b(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	top_index;
	int		chunk;

	i = 0;
	while (a->size != 0)
	{
		chunk = 0.000000053 * (a->size * a->size) + 0.03 * a->size + 14.5;
		top_index = get_top_index(a);
		if (top_index <= i)
		{
			cmd(PB, a, b);
			i++;
		}
		else if (top_index > i && top_index <= i + chunk)
		{
			cmd(PB, a, b);
			cmd(RB, a, b);
			i++;
		}
		else if (top_index > (i + chunk))
			cmd(RA, a, b);
	}
}

static void	sort_b(t_stack *a, t_stack *b, size_t length)
{
	size_t	i;
	t_node	*node;

	node = b->bottom;
	i = 0;
	while (i < b->size && node->index != length)
	{
		node = node->prev;
		i++;
	}
	while (i < b->size / 2 && i >= 0)
	{
		cmd(RRB, a, b);
		i--;
	}
	while (i >= b->size / 2 && i < b->size - 1)
	{
		cmd(RB, a, b);
		i++;
	}
}

void	b_to_a(t_stack *a, t_stack *b)
{
	int	length;

	length = b->size - 1;
	while (b->size != 0)
	{
		sort_b(a, b, length);
		cmd(PA, a, b);
		length--;
	}
}

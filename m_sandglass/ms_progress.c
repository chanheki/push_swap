/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_progress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 00:50:09 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/10 04:08:45 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	arg_indexer(t_stack *stack_a)
{
	t_node	*temp;
	t_node	*temp_2;

	temp = stack_a->top;
	while (temp)
	{
		temp_2 = stack_a->top;
		while (temp_2)
		{
			if (temp->value > temp_2->value)
				temp->index++;
			temp_2 = temp_2->next;
		}
		temp = temp->next;
	}
}

static size_t	get_top(t_stack *stack)
{
	return (stack->top->index);
}

void	a_to_b(t_stack *a, t_stack *b, int chunk, size_t i)
{
	size_t	get_top_numb;

	while (a->size != 0)
	{
		get_top_numb = get_top(a);
		// printf("get top index: %zu, i: %zu, chunk: %d \n", get_top_numb, i, chunk);
		if (get_top_numb <= i)
		{
			cmd(PB, a, b);
			i++;
		}
		else if (get_top_numb > i && get_top_numb <= i + chunk)
		{
			cmd(PB, a, b);
			cmd(RB, a, b);
			i++;
		}
		else if (get_top_numb > (i + chunk))
		{
			if (i < a->size / 2 && i >= 0)
				cmd(RRA, a, b);
			else
				cmd(RA, a, b);
		}
	}
}

void	sort_b(t_stack *a, t_stack *b, size_t length)
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
	// printf("get b length => %d \n", length);

	while (b->size != 0)
	{
		sort_b(a, b, length);
		cmd(PA, a, b);
		length--;
	}
}

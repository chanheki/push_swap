/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mr_arrange_big_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:49:06 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/02 03:07:35 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	get_max_bits(t_stack *stack_a)
{
	t_node		*temp;
	size_t		max;
	int			max_bits;

	temp = stack_a->top;
	max = temp->index;
	max_bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	arrange_big_args(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;
	int		i;
	int		j;
	int		max_bits;
	int		size;

	i = 0;
	temp = stack_a->top;
	max_bits = get_max_bits(stack_a);
	size = stack_a->size;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			temp = stack_a->top;
			if (((temp->index >> i) & 1) == 1)
				cmd(RA, stack_a, stack_b);
			else
				cmd(PB, stack_a, stack_b);
		}
		while (stack_b->size > 0)
			cmd(PA, stack_a, stack_b);
		i++;
	}
}

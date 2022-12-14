/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mr_arrange_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:24:32 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/02 03:07:33 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_arranged(t_stack *stack_a)
{
	size_t	i;
	t_node	*temp;

	i = 0;
	temp = stack_a->top;
	while (temp)
	{
		if (i != temp->index)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

void	arrange_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_arranged(stack_a))
		return ;
	if (stack_a->size <= 5)
		return (arrange_under_5_args(stack_a, stack_b));
	arrange_big_args(stack_a, stack_b);
}

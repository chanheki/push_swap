/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_indexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:31:28 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/14 00:03:36 by chanheki         ###   ########.fr       */
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

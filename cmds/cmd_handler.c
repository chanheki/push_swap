/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 03:05:39 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/02 05:54:06 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cmd(t_cmd_case cmd, t_stack *stack_a, t_stack *stack_b)
{
	if (cmd == SA)
		swap(stack_a, stack_b, SA);
	else if (cmd == SB)
		swap(stack_a, stack_b, SB);
	else if (cmd == SS)
		swap(stack_a, stack_b, SS);
	else if (cmd == PA)
		push(stack_a, stack_b, PA);
	else if (cmd == PB)
		push(stack_a, stack_b, PB);
	else if (cmd == RA)
		rotate(stack_a, stack_b, RA);
	else if (cmd == RB)
		rotate(stack_a, stack_b, RB);
	else if (cmd == RR)
		rotate(stack_a, stack_b, RR);
	else if (cmd == RRA)
		reverse_rotate(stack_a, stack_b, RRA);
	else if (cmd == RRB)
		reverse_rotate(stack_a, stack_b, RRB);
	else if (cmd == RRR)
		reverse_rotate(stack_a, stack_b, RRR);
	else
		return (0);
	return (1);
}

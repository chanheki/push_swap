/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_under_5_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:16:36 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/01 21:13:59 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	arrange_2_args(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size != 2)
		error_exitor();
	if (stack_a->top->index > stack_a->bottom->index)
		cmd(SA, stack_a, stack_b);
}

static void	arrange_3_args(t_stack *stack_a, t_stack *stack_b)
{
	int	case_num;

	if (stack_a->size != 3)
		error_exitor();
	case_num = identifty_case(stack_a);
	if (case_num == 1)
		cmd(SA, stack_a, stack_b);
	else if (case_num == 2)
	{
		cmd(SA, stack_a, stack_b);
		cmd(RRA, stack_a, stack_b);
	}
	else if (case_num == 3)
		cmd(RA, stack_a, stack_b);
	else if (case_num == 4)
	{
		cmd(SA, stack_a, stack_b);
		cmd(RA, stack_a, stack_b);
	}
	else if (case_num == 5)
		cmd(RRA, stack_a, stack_b);
}

static	void	arrange_4_args(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size != 4)
		error_exitor();
	push_b_lowest(stack_a, stack_b);
	arrange_3_args(stack_a, stack_b);
	cmd(PA, stack_a, stack_b);
}

static	void	arrange_5_args(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size != 5)
		error_exitor();
	push_b_lowest(stack_a, stack_b);
	push_b_second_lowest(stack_a, stack_b);
	arrange_3_args(stack_a, stack_b);
	cmd(PA, stack_a, stack_b);
	cmd(PA, stack_a, stack_b);
}

void	arrange_under_5_args(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		return (arrange_2_args(stack_a, stack_b));
	if (stack_a->size == 3)
		return (arrange_3_args(stack_a, stack_b));
	if (stack_a->size == 4)
		return (arrange_4_args(stack_a, stack_b));
	if (stack_a->size == 5)
		return (arrange_5_args(stack_a, stack_b));
}

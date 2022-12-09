/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:53:21 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/10 04:55:03 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stacks(&stack_a, &stack_b);
	arg_validator(argc, argv);
	arg_parser(argc, argv, &stack_a);
	arg_indexer(&stack_a);
	sort_stack(&stack_a, &stack_b);
	clear_stack(&stack_a, &stack_b);
	return (0);
}

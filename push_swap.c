/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:53:21 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/10 04:00:34 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	// checker_argc_argv(argc, argv);
	init_stacks(&stack_a, &stack_b);
	arg_validator(argc, argv);
	arg_parser(argc, argv, &stack_a);
	//TODO: model Radix
	arg_indexer(&stack_a);
	// arrange_stack(&stack_a, &stack_b);
	//TODO: model Merge
	// show_stack_top_bottom(&stack_a);
	sort_stack(&stack_a, &stack_b);

	//TODO: show
	// printf("======> %d\n", size_identifier(3,1,2, ASCENDING));
	// printf("stack A \n");
	// show_stack(&stack_a);
	// show_stack_top_bottom(&stack_a);
	// printf("stack B \n");
	// show_stack(&stack_b);
	// show_stack_top_bottom(&stack_b);
	clear_stack(&stack_a, &stack_b);
	return (0);
}

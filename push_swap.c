/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:53:21 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/29 23:23:05 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stacks(&stack_a, &stack_b);
	arg_validator(argc, argv);
	// TODO parsing
	arg_parser(argc, argv, &stack_a);
	
	//TODO: business

	t_stack *pA = &stack_a;
	t_stack *pB = &stack_b;

	swap(pA,pB,STACK_A);
	show_stack_top_bottom(pA);
	show_stack(pA);

	// push(pA,pB,STACK_B);
	push(pA,pB,STACK_B);
	printf("stack B -> \n");
	show_stack_top_bottom(pB);
	show_stack(pB);
	printf("stack A -> \n");
	show_stack_top_bottom(pA);
	show_stack(pA);

	printf("E N D P R O G R A M \n");
	return (0);
}

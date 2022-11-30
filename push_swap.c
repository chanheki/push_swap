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

	printf("- E N D P R O G R A M - \n");
	return (0);
}

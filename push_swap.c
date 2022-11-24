/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:53:21 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/24 20:43:28 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	// init
	init_stacks(&stack_a, &stack_b);
	// parsing
	arg_parser(argc, argv, &stack_a);
	// validate
	arg_validator(argc, argv);

	//TODO: business
	return (0);
}

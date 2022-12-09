/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:44:51 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/10 04:48:17 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

//TODO show stack delete
void	show_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		printf("[index: %zu] %d \n", node->index, node->value);
		node = node->next;
	}
}

//TODO show top delete
void	show_stack_top_bottom(t_stack *stack)
{
	if (stack->top)
		printf("stack top: %d \n", stack->top->value);
	else
		printf("stack top: null \n");
	if (stack->bottom)
		printf("stack bottom: %d \n", stack->bottom->value);
	else
		printf("stack bottom: null \n");
}

//TODO show top_bottom info delete
void	show_stack_top_bottom_info(t_stack *stack)
{
	if (stack->top)
		printf("stack top NEXT: %d \n", stack->top->next->value);
	else
		printf("stack top: null \n");
	if (stack->bottom)
		printf("stack bottom PREV: %d \n", stack->bottom->prev->value);
	else
		printf("stack bottom: null \n");
}


//TODO show top_bottom info delete
void	checker_argc_argv(int argc, char **argv)
{
	printf("argc: %d \n", argc);
	for (int i = 0 ; i <= argc ; i++)
	{
		printf("%d -> %s \n", i, *argv);
		argv++;
	}
}


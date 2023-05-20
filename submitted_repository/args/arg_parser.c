/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:15:29 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/10 05:56:02 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	append_stack(t_stack *stack_a, int data)
{
	t_node		*duplicate_check;
	t_node		*node;

	duplicate_check = stack_a->top;
	node = new_node(data);
	while (duplicate_check)
	{
		if (duplicate_check->value == node->value)
			error_exitor();
		duplicate_check = duplicate_check->next;
	}
	if (stack_a->size != 0)
	{
		stack_a->bottom->next = node;
		node->prev = stack_a->bottom;
	}
	else
		stack_a->top = node;
	stack_a->bottom = node;
	stack_a->size++;
}

void	arg_parser(int argc, char **argv, t_stack *stack_a)
{
	int		index;
	char	**temp;
	char	**splited;
	int		separated_arg;

	index = 1;
	while (index < argc)
	{	
		splited = ft_split(argv[index], ' ');
		temp = splited;
		while (*splited)
		{
			separated_arg = ft_atoi(*splited);
			append_stack(stack_a, separated_arg);
			free(*splited);
			splited++;
		}
		free(temp);
		index++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:15:29 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/24 06:05:15 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	append_stack(t_stack *stack_a, int data)
{
	t_node	*temp;
	t_node	*node;

	temp = stack_a->top;
	node = new_node(data);
	while (temp)
	{
		if (temp->value == node->value)
			error_exit();
		temp = temp->next;
	}
	if (stack_a->size == 0)
		stack_a->top = node;
	else
	{
		node->prev = last_node(stack_a);
		last_node(stack_a)->next = node;
	}
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

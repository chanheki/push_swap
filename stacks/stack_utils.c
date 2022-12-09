/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:23:28 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/10 04:00:59 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_b->size = 0;
	stack_b->top = NULL;
	stack_b->bottom = NULL;
}

t_node	*new_node(int data)
{
	t_node		*new_node;
	static int	static_index = 0;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_exitor();
	new_node->value = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = static_index; //TODO: indexing recent ++
	return (new_node);
}

t_node	*pop(t_stack *stack)
{
	t_node	*ret_node;

	ret_node = stack->top;
	if (stack->size > 1)
		stack->top = stack->top->next;
	else
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	stack->size--;
	return (ret_node);
}

void	clear_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	while (stack_b->size)
	{
		node = pop(stack_b);
		if (node)
			break ;
		free(node);
	}
	while (stack_a->size)
	{
		node = pop(stack_a);
		if (node)
			break ;
		free(node);
	}
}

void	large_command(t_stack *a, t_stack *b)
{
	int				i;
	int				x;
	int				chunk;

	i = 0;
	x = a->size;
	chunk = 0.000000053 * (x * x) + 0.03 * x + 14.5;
	// printf("chunk = %d \n", chunk);
	// printf("~~~> stack A \n");
	// show_stack(a);
	a_to_b(a, b, chunk, i);
	// printf("~~~~> stack B \n");
	// show_stack(b);
	b_to_a(a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	// int		depth;
	size_t	i;
	size_t	n;
	i = 0;
	n = a->size;
	if (is_sorted(a, n))
		return ;
	if (n <= 6)
		basis_sort(a, b);
	else
	{
		large_command(a, b);
	}
}

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


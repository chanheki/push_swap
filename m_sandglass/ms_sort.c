/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:55:34 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/10 04:59:25 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sandglass_sort(t_stack *a, t_stack *b)
{
	int				i;
	int				x;
	int				chunk;

	i = 0;
	x = a->size;
	chunk = 0.000000053 * (x * x) + 0.03 * x + 14.5;
	a_to_b(a, b, chunk, i);
	b_to_a(a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = a->size;
	if (is_sorted(a, n))
		return ;
	if (n <= 6)
		basis_sort(a, b);
	else
		sandglass_sort(a, b);
}

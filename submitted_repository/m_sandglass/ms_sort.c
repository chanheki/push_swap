/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:55:34 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/13 23:47:39 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sandglass_sort(t_stack *a, t_stack *b)
{
	a_to_b(a, b);
	b_to_a(a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	n;

	if (!a->size)
		return ;
	i = 0;
	n = a->size;
	if (is_sorted(a, n))
		return ;
	if (n <= 6)
		basis_sort(a, b);
	else
		sandglass_sort(a, b);
}

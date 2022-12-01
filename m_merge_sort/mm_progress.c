/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_progress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:42:48 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/02 06:18:13 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	// int		depth;
	size_t	n;

	if (is_sorted(a, a->size))
		return ;
	n = a->size;
	if (n <= 6)
		basis_sort(a, b);
}

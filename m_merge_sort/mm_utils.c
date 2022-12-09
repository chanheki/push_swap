/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 03:05:11 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/10 00:37:44 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_pow(int a, int b)
{
	int	pow;

	pow = 1;
	while (b-- > 0)
		pow *= a;
	return (pow);
}

int	size_identifier(int a, int b, int c, t_order_case order)
{
	if (!a || !b || !c)
		return (0);
	if (order == ASCENDING)
	{
		if (a > b && a > c)
			return (1);
		else if (b > a && b > c)
			return (2);
		else
			return (3);
	}
	else
	{
		if (a < b && a < c)
			return (1);
		else if (b < a && b < c)
			return (2);
		else
			return (3);
	}
}

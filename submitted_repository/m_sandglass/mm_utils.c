/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 03:05:11 by chanheki          #+#    #+#             */
/*   Updated: 2022/12/13 23:09:44 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	size_identifier(int a, int b, int c, t_order_case order)
{
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

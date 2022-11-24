/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 02:59:39 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/24 02:59:40 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>

int	ft_isdigit(int c);

static int	ft_isspace(const char str)
{
	if (str == ' ' || str == '\n' || str == '\t')
		return (1);
	if (str == '\v' || str == '\f' || str == '\r')
		return (1);
	return (0);
}

long long	ft_atoll(const char *str)
{
	size_t			i;
	size_t			result;
	int				flag;

	i = 0;
	result = 0;
	flag = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result >= 9223372036854775808U && flag == -1)
		return (0);
	else if (result >= 9223372036854775807 && flag == 1)
		return (-1);
	return (result * flag);
}

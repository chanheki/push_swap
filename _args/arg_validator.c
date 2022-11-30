/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:15:33 by chanheki          #+#    #+#             */
/*   Updated: 2022/11/29 21:45:26 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	digit_checker(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
static int	int_checker(char *str)
{
	long long	check;

	check = ft_atoll(str);
	if (check >= -2147483648 && check <= 2147483647)
		return (1);
	return (0);
}

static	int	white_space_checker(char *str)
{
	size_t	index;
	char	*temp;

	index = 0;
	temp = str;
	while (*temp)
	{
		if (*temp == ' ' || *temp == '\n' || *temp == '\r'
			|| *temp == '\t' || *temp == '\v' || *temp == '\f')
			index++;
		temp++;
	}
	if (index == ft_strlen(str))
		error_exitor();
	return (1);
}

static	int	arg_checker(char *str)
{
	if (!int_checker(str) || !digit_checker(str))
		return (0);
	return (1);
}

void	arg_validator(int argc, char **argv)
{
	int		index;
	char	**temp;
	char	**splited;
	char	*separated_arg;

	if (argc < 1)
		error_exitor();
	index = 1;
	while (index < argc)
	{
		white_space_checker(argv[index]);
		splited = ft_split(argv[index], ' ');
		temp = splited;
		while (*splited)
		{
			separated_arg = *splited;
			if (!arg_checker(separated_arg))
				error_exitor();
			free(*splited);
			splited++;
		}
		free(temp);
		index++;
	}
}

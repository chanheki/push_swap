/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:17:08 by chanheki          #+#    #+#             */
/*   Updated: 2022/07/25 22:33:21 by chanheki         ###   ########.fr       */
/*                                             /Users/chanheki/7_2/libft/ft_strlen.c                               */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;

	length = ft_strlen(s) + 1;
	while (length--)
		if (*(s + length) == (unsigned char)c)
			return ((char *)(s + length));
	return (NULL);
}

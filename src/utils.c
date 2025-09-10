/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:31:46 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/02 12:37:36 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	is_whitespace(char c)
{
	if ((c == ' ') || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_symbol(char c)
{
	if ((c == '+') || (c == '-'))
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if ((c <= '9') && (c >= '0'))
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	int			i;
	long		res;
	long		pos;

	i = 0;
	res = 0;
	pos = 1;
	while (is_whitespace(str[i]))
		i++;
	if (is_symbol(str[i]))
	{
		if (str[i] == '-')
			pos = -pos;
		i++;
	}
	while (is_digit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		exit_prob();
	return (res * pos);
}

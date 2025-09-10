/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:25:44 by anfiorit          #+#    #+#             */
/*   Updated: 2025/08/27 16:34:10 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	conv2hexp(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += conv2hexp(n / 16, base);
	ft_putchar(base[n % 16]);
	len++;
	return (len);
}

void	ft_u2char(unsigned int i)
{
	char	c;

	c = (i + 48);
	write (1, &c, 1);
}

int	conv2u(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += conv2u(n / 10);
	ft_u2char(n % 10);
	len++;
	return (len);
}

int	conv2str(char *str)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:27:51 by anfiorit          #+#    #+#             */
/*   Updated: 2025/07/10 12:53:59 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_int2char(int i)
{
	char	c;

	c = (i + 48);
	write (1, &c, 1);
}

int	conv2int(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		len++;
		n = -n;
	}
	if (n > 9)
		len += conv2int(n / 10);
	ft_int2char(n % 10);
	len++;
	return (len);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

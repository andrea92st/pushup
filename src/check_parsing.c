/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:18:19 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/10 18:16:48 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_int_valid(char *buffer, int *size)
{
	long	res;
	int		i;

	i = 0;
	if (buffer[i] == '+' || buffer[i] == '-')
		i++;
	if (!(buffer[i] >= '0' && buffer[i] <= '9'))
		exit_prob();
	while (buffer[i])
	{
		if (!(buffer[i] >= '0' && buffer[i] <= '9'))
			exit_prob();
		i++;
	}
	res = ft_atol(buffer);
	if (res > INT_MAX || res < INT_MIN)
		exit_prob();
	(*size)++;
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	value_exists(t_node *head, int x)
{
	while (head)
	{
		if (head->value == x)
			return (1);
		head = head->next;
	}
	return (0);
}

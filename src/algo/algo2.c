/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:58:46 by fio               #+#    #+#             */
/*   Updated: 2025/09/10 18:16:50 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_value_in_chunk(t_node **stack, int first, int last)
{
	t_node	*test;

	test = *stack;
	while (test)
	{
		if (test->value >= first && test->value <= last)
			return (1);
		test = test->next;
	}
	return (0);
}

int	choose_chunk_size(t_node **stack)
{
	int	len;

	len = len_stack(stack);
	if (len > 400)
		return (45);
	else if (len > 300)
		return (25);
	else if (len > 100)
		return (15);
	else if (len > 20)
		return (15);
	else
		return (3);
}

int	chunk_is_not_sorted(t_node **b, int top, int bottom)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while (i < top)
	{
		tmp = tmp->next;
		i++;
	}
	while (i < bottom)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

int	is_buffer_digit(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] <= '9' && buffer[i] >= '0')
			i++;
		else
			return (1);
	}
	return (0);
}

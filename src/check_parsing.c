/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:18:19 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/22 13:04:44 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_node(t_node **stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit_prob();
	new->value = value;
	new->next = *stack;
	*stack = new;
}

int	check_double(long n, char **av, int max, int start)
{
	int		i;
	long	tmp;

	i = start;
	while (i < max)
	{
		tmp = ft_atol(av[i]);
		if (n == tmp)
			return (1);
		i++;
	}
	return (0);
}

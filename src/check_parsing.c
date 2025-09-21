/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:18:19 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/21 15:38:24 by fio              ###   ########.fr       */
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

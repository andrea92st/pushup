/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_value_to_stack_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:06:35 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/20 13:38:07 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_node **stack, int value)
{
	t_node	*new;
	if (value_exists(*stack, value) == 1)
		exit_prob();
	
	new = malloc(sizeof(t_node));
	if (!new)
		exit_prob();
	new->value = value;
	new->next = *stack;
	*stack = new;
}


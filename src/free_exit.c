/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:54:47 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/15 20:07:08 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	while (stack_a)
	{
		tmp_a = stack_a->next;
		free(stack_a);
		stack_a = tmp_a;
	}
	while (stack_b)
	{
		tmp_b = stack_b->next;
		free(stack_b);
		stack_b = tmp_b;
	}
}

void	exit_prob(void)
{
	ft_printf("Error\n");
	exit(1);
}

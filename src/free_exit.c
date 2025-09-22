/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:54:47 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/22 12:44:46 by fio              ###   ########.fr       */
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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

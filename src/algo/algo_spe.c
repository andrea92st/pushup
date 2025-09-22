/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_spe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:54:21 by fio               #+#    #+#             */
/*   Updated: 2025/09/22 13:09:16 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **stack)
{
	int	a;
	int	b;

	a = (*stack)->value;
	b = (*stack)->next->value;
	if (a > b)
		sa(stack);
}

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b > c && a > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a > b && b < c && a < c)
		sa(stack);
	else if (a < b && b > c && a > c)
		rra(stack);
	return ;
}

void	sort_spec(t_node **a, t_node **b, int size)
{
	int	i;
	int	len;

	i = 0;
	while (size > 3)
	{
		len = len_stack(a);
		i = find_min_index(*a);
		if (i <= len / 2)
			while (i-- > 0)
				ra(a);
		else
		{
			while (i < len)
			{
				rra(a);
				i++;
			}
		}
		pb(a, b);
		size--;
	}
	sort_three(a);
}

void	sort_little(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
	{
		sort_spec(a, b, size);
		if ((*b) && (*b)->next && (*b)->value < (*b)->next->value)
			sb(b);
		while (*b)
			pa(a, b);
	}
}

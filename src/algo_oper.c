/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:44:57 by fio               #+#    #+#             */
/*   Updated: 2025/09/01 13:23:43 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_with_rra(int count, t_node **a, t_node **b, int mid)
{
	int	i;

	i = 0;
	while (i < count)
	{
		rra(a);
		i++;
	}
	pb(a, b);
	if (mid <= (*b)->value)
		rb(b);
}

void	top_with_ra(int count, t_node **a, t_node **b, int mid)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ra(a);
		i++;
	}
	pb(a, b);
	if (mid <= (*b)->value)
		rb(b);
}

void	sort_with_rb(t_node **b, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		rb(b);
		i++;
	}
}

void	sort_with_rrb(t_node **b, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		rrb(b);
		i++;
	}
}

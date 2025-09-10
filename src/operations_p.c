/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:28:40 by fio               #+#    #+#             */
/*   Updated: 2025/08/27 16:37:09 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*top;

	if (!b || !*b)
		return ;
	top = *b;
	*b = top->next;
	top->next = *a;
	*a = top;
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*top;

	if (!a || !*a)
		return ;
	top = *a;
	*a = top->next;
	top->next = *b;
	*b = top;
	write(1, "pb\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:11:09 by fio               #+#    #+#             */
/*   Updated: 2025/08/27 16:42:35 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*new_head;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next->next)
		last = last->next;
	new_head = last->next;
	last->next = NULL;
	new_head->next = *a;
	*a = new_head;
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	t_node	*new_head;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	while (last->next->next)
		last = last->next;
	new_head = last->next;
	last->next = NULL;
	new_head->next = *b;
	*b = new_head;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	t_node	*new_head_a;
	t_node	*last_a;
	t_node	*new_head_b;
	t_node	*last_b;

	if (!b || !*b || !(*b)->next || !a || !*a || !(*a)->next)
		return ;
	last_b = *b;
	while (last_b->next->next)
		last_b = last_b->next;
	new_head_b = last_b->next;
	last_b->next = NULL;
	new_head_b->next = *b;
	*b = new_head_b;
	last_a = *a;
	while (last_a->next->next)
		last_a = last_a->next;
	new_head_a = last_a->next;
	last_a->next = NULL;
	new_head_a->next = *a;
	*a = new_head_a;
	write(1, "rrr\n", 4);
}

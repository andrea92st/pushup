/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:02:43 by fio               #+#    #+#             */
/*   Updated: 2025/08/27 16:39:59 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*last;
	t_node	*head;

	if (!a || !*a || !(*a)->next)
		return ;
	head = *a;
	*a = head->next;
	head->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = head;
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	t_node	*last;
	t_node	*head;

	if (!b || !*b || !(*b)->next)
		return ;
	head = *b;
	*b = head->next;
	head->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = head;
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	t_node	*last_b;
	t_node	*head_b;
	t_node	*last_a;
	t_node	*head_a;

	if (!b || !*b || !(*b)->next || !a || !*a || !(*a)->next)
		return ;
	head_b = *b;
	*b = head_b->next;
	head_b->next = NULL;
	last_b = *b;
	while (last_b->next)
		last_b = last_b->next;
	last_b->next = head_b;
	head_a = *a;
	*a = head_a->next;
	head_a->next = NULL;
	last_a = *a;
	while (last_a->next)
		last_a = last_a->next;
	last_a->next = head_a;
	write(1, "rr\n", 3);
}

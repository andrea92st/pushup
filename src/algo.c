/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:07:41 by fio               #+#    #+#             */
/*   Updated: 2025/08/27 16:13:23 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_algo(t_node **a, t_node **b)
{
	push_to_b(a, b);
	sort_and_pushback(a, b);
}

void	sort_and_pushback(t_node **a, t_node **b)
{
	int	min_val;
	int	sort_rb;
	int	sort_rrb;

	while (*b)
	{
		min_val = find_min(b);
		sort_rb = pos_top(b, min_val, min_val);
		sort_rrb = pos_bottom(b, min_val, min_val);
		if (sort_rb <= sort_rrb)
			sort_with_rb(b, sort_rb);
		else
			sort_with_rrb(b, sort_rrb);
		pa(a, b);
		ra(a);
	}
}

void	push_to_b(t_node **a, t_node **b)
{
	int	size_chunk;
	int	head_chunk;
	int	tail_chunk;
	int	len_max;

	len_max = len_stack(a);
	size_chunk = choose_chunk_size(a);
	head_chunk = 0;
	tail_chunk = size_chunk - 1;
	while (*a)
	{
		if (tail_chunk >= len_max)
			tail_chunk = len_max - 1;
		while (is_value_in_chunk(a, head_chunk, tail_chunk))
			find_and_send(a, b, head_chunk, tail_chunk);
		head_chunk += size_chunk;
		tail_chunk += size_chunk;
		if (head_chunk >= len_max)
			break ;
	}
}

void	find_and_send(t_node **a, t_node **b, int top, int bottom)
{
	int	count_moves_bottom;
	int	count_moves_top;
	int	mid;

	mid = (top + bottom / 2);
	count_moves_top = pos_top(a, top, bottom);
	count_moves_bottom = pos_bottom(a, top, bottom);
	if (count_moves_top == 0)
	{
		pb(a, b);
		return ;
	}
	else if (count_moves_top <= count_moves_bottom)
		top_with_ra(count_moves_top, a, b, mid);
	else
		top_with_rra(count_moves_bottom, a, b, mid);
}

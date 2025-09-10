/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remap_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:56:33 by fio               #+#    #+#             */
/*   Updated: 2025/08/27 16:46:42 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_stack_val(t_node **a)
{
	int	len_max;
	int	*tab;

	len_max = len_tab(a);
	if (len_max <= 1)
		return ;
	tab = malloc (sizeof (int) * len_max);
	if (tab == NULL)
		return ;
	copy_tab(tab, a);
	newval_tab(tab, a, len_max);
	free(tab);
}

void	copy_tab(int *tab, t_node **a)
{
	t_node	*index;
	int		i;

	i = 0;
	index = *a;
	while (index)
	{
		tab[i] = index->value;
		index = index->next;
		i++;
	}
}

int	len_tab(t_node **a)
{
	t_node	*tmp;
	int		len;

	len = 0;
	tmp = *a;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	newval_tab(int *tab, t_node **a, int len)
{
	int	i;
	int	count;
	int	val;

	count = 0;
	while (count < len)
	{	
		i = 0;
		val = 0;
		while (i < len)
		{
			if (tab[count] > tab[i])
				val++;
			i++;
		}
		replace_val_stack(val, count, a);
		count++;
	}
}

void	replace_val_stack(int val, int index, t_node **a)
{
	t_node	*i;
	int		sniper;

	sniper = 0;
	i = *a;
	while (sniper < index)
	{
		i = i->next;
		sniper++;
	}
	i->value = val;
}

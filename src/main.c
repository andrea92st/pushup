/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:31:18 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/10 18:14:48 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	if (argc == 1)
		exit_prob();
	if (argc == 2)
		parse_argument(argv[1], &size, &stack_a);
	if (argc > 2)
		size = main_part_2(argc, argv, size, &stack_a);
	if (is_sorted(stack_a) == 0)
		return (free_stack(stack_a, stack_b), 1);
	change_stack_val(&stack_a);
	if (size <= 5)
		sort_little(&stack_a, &stack_b, size);
	if (size > 5)
		main_algo(&stack_a, &stack_b);
	free_stack(stack_a, stack_b);
	return (0);
}

int	main_part_2(int argc, char **argv, int size, t_node **a)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		is_int_valid(argv[i], &size);
		push_node_checked(a, ft_atol(argv[i]));
		i--;
	}
	return (size);
}

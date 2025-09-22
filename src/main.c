/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:31:18 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/22 13:03:47 by fio              ###   ########.fr       */
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
	if (argc == 1)
		return (0);
	if (argc == 2)
		size = arg_is_2(argv[1], &stack_a);
	else if (argc > 2)
		size = main_part_2(argc, argv, &stack_a);
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

int	main_part_2(int argc, char **argv, t_node **a)
{
	int	i;
	int	size;

	if (argv[0] == NULL)
		exit_prob();
	i = argc - 1;
	size = check_argv(argv, argc);
	while (i > 0)
	{
		push_node(a, ft_atol(argv[i]));
		i--;
	}
	return (size);
}

int	check_argv(char **av, int ac)
{
	long	tmp;
	int		i;

	i = 1;
	while (i < ac)
	{
		tmp = ft_atol(av[i]);
		if (check_double(tmp, av, i, 1) == 1)
			exit_prob();
		if (tmp < INT_MIN || tmp > INT_MAX)
			exit_prob();
		i++;
	}
	return (i - 1);
}

char	**split_check(char *arg)
{
	char	**tab;
	int		i;
	long	tmp;

	tab = ft_split(arg);
	i = 0;
	while (tab[i])
	{
		if (is_buffer_digit(tab[i]) == 1)
		{
			free_tab(tab);
			exit_prob();
		}
		tmp = ft_atol(tab[i]);
		if ((tmp < INT_MIN || tmp > INT_MAX)
			|| (check_double(tmp, tab, i, 0) == 1))
		{
			free_tab(tab);
			exit_prob();
		}
		i++;
	}
	return (tab);
}

int	arg_is_2(char *arg, t_node **a)
{
	char	**tab;
	int		i;
	int		size;

	i = 0;
	tab = split_check(arg);
	while (tab[i])
		i++;
	size = i;
	i -= 1;
	while (i >= 0)
	{
		push_node(a, ft_atol(tab[i]));
		i--;
	}
	free_tab(tab);
	return (size);
}

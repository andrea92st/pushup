/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:31:18 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/20 13:15:36 by fio              ###   ########.fr       */
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
		exit_prob();
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
/*jpense jpeu split, tout foutre dans un tab et appl lalgo de size > 2
bien eco+*/
int	main_part_2(int argc, char **argv, t_node **a)
{
	int	i;
	int	size;

	i = argc - 1;
	size = check_argv(argv, argc);
	while (i > 0)
	{
		push_node(a, ft_atol(argv[i]));
		i--;
	}
	return (size);
}

int check_argv(char **av, int ac)
{
	long	tmp;
	int	i;
	
	i = 1;
	while(i < ac)
	{
		tmp = ft_atol(av[i]);
		if(tmp <= INT_MIN || tmp >= INT_MAX)
			exit_prob();
		i++;
	}
	return (i - 1);

}

char **splitos(char *arg)
{
	char	**tab;
	int		i;
	long	tmp;

	tab = ft_split(arg);
	i = 0;
	while (tab[i])
	{
		tmp = ft_atol(tab[i]);
		if(tmp <= INT_MIN || tmp >= INT_MAX)
		{
			free_tab(tab);
			exit_prob();
		}
		i++;	
	}
	return(tab);
}

int arg_is_2(char *arg, t_node **a)
{
	char	**tab;
	int		i;
	int		size;

	i = 0;
	tab = splitos(arg);
	while(tab[i])
		i++;
	size = i;
	i -= 1;
	while(i >= 0)
	{
		push_node(a, ft_atol(tab[i]));
		i--;
	}
	free_tab(tab);
	return (size);
}

void free_tab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])	
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

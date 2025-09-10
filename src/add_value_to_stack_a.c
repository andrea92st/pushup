/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_value_to_stack_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:06:35 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/03 13:46:05 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_argument(char *buffer, int *size_stack, t_node **stack_a)
{
	long	value;

	if (is_buffer_digit(buffer) == 1)
	{
		free(buffer);
		exit_prob();
	}
	value = ft_atol(buffer);
	push_node_checked(stack_a, value);
	(*size_stack)++;
}

void	parse_argument(char *argv, int *size_stack, t_node **stack_a)
{
	int		i;
	int		start;
	int		j;
	char	*buffer;

	i = 0;
	while (argv[i])
		i++;
	i--;
	while (i >= 0)
	{
		buffer = extract_next_token(argv, &i, &start, &j);
		if (!buffer || is_buffer_digit(buffer) == 1)
		{
			free(buffer);
			exit_prob();
		}
		process_argument(buffer, size_stack, stack_a);
		free(buffer);
		i = j - 1;
	}
}

char	*extract_next_token(char *argv, int *i, int *start, int *j)
{
	int		len;
	char	*buffer;
	int		n;

	while (*i >= 0 && argv[*i] == ' ')
		(*i)--;
	if (*i < 0)
		return (NULL);
	*j = *i;
	while (*j >= 0 && argv[*j] != ' ')
		(*j)--;
	*start = *j + 1;
	len = *i - *start + 1;
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	n = 0;
	while (*start <= *i)
		buffer[n++] = argv[(*start)++];
	buffer[n] = '\0';
	return (buffer);
}

void	push_node(t_node **stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit_prob();
	new->value = value;
	new->next = *stack;
	*stack = new;
}

void	push_node_checked(t_node **stack, int x)
{
	if (value_exists(*stack, x) == 1)
		exit_prob();
	push_node(stack, x);
}

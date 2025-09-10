/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfiorit <anfiorit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:52:23 by anfiorit          #+#    #+#             */
/*   Updated: 2025/09/03 13:59:49 by anfiorit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

void	ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		conv2hexp(unsigned long n, char *base);
int		conv2str(char *str);
int		conv2int(int n);
int		conv2u(unsigned int n);

void	exit_prob(void);
long	ft_atol(const char *str);
int		ft_strlen(char *str);
void	push_node(t_node **stack, int value);
void	is_int_valid(char *buffer, int *size);
void	free_stack(t_node *stack_a, t_node *stack_b);
int		value_exists(t_node *head, int n);
void	push_node_checked(t_node **stack, int n);
int		is_digit(char c);
int		is_symbol(char c);
int		is_whitespace(char c);
int		is_sorted(t_node *stack);
void	replace_val_stack(int val, int index, t_node **a);
void	newval_tab(int *tab, t_node **a, int len);
int		len_tab(t_node **a);
void	copy_tab(int *tab, t_node **a);
void	change_stack_val(t_node **a);
void	sort_two(t_node **stack);
void	sort_three(t_node **stack);
int		find_min_index(t_node *tmp);
int		len_stack(t_node **stack);
void	main_algo(t_node **a, t_node **b);
int		chunk_is_not_sorted(t_node **b, int top, int bottom);
int		choose_chunk_size(t_node **stack);
int		is_value_in_chunk(t_node **stack, int first, int last);
void	sort_and_pushback(t_node **a, t_node **b);
void	push_to_b(t_node **a, t_node **b);
void	find_and_send(t_node **a, t_node **b, int top, int bottom);
void	top_with_rra(int count, t_node **a, t_node **b, int mid);
void	top_with_ra(int count, t_node **a, t_node **b, int mid);
void	sort_with_rb(t_node **b, int count);
void	sort_with_rrb(t_node **b, int count);
int		find_min(t_node **b);
int		pos_top(t_node **a, int top, int bottom);
int		pos_bottom(t_node **a, int top, int bottom);
void	sort_spec(t_node **a, t_node **b, int size);
int		main_part_2(int argc, char **argv, int size, t_node **a);
void	sort_little(t_node **a, t_node **b, int size);
char	*extract_next_token(char *argv, int *i, int *start, int *j);
void	parse_argument(char *argv, int *size_stack, t_node **stack_a);
void	process_argument(char *buffer, int *size_stack, t_node **stack_a);
int		is_buffer_digit(char *buffer);

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif
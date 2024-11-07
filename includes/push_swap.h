/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:21:33 by raamorim          #+#    #+#             */
/*   Updated: 2024/11/07 14:21:33 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/libft/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct p_list
{
	int				number;
	int				index;
	int				cost;
	bool			below_median;
	bool			cheapest;
	struct p_list	*next;
	struct p_list	*prev;
	struct p_list	*target;
}					t_stack;

// moves
/* static void push(t_stack **b_stack, t_stack **a_stack); */
void	pa(t_stack **b_stack, t_stack **a_stack);
void	pb(t_stack **a_stack, t_stack **b_stack);

/* static void reverse(t_stack **stack); */
void	rra(t_stack **a_stack);
void	rrb(t_stack **b_stack);
void	rrr(t_stack **a_stack, t_stack **b_stack);

/* static void swap(t_stack **stack); */
void	sa(t_stack **a_stack);
void	sb(t_stack **b_stack);
void	ss(t_stack **a_stack, t_stack **b_stack);

/* static void rotate(t_stack **stack); */
void	ra(t_stack **a_stack);
void	rb(t_stack **b_stack);
void	rr(t_stack **a_stack, t_stack **b_stack);

// algorithms
void	sort_three(t_stack **stack);
void	sort_four(t_stack **a_stack, t_stack **b_stack);
void	sort_five(t_stack **a_stack, t_stack **b_stack);
void	push_swap(t_stack **a_stack, t_stack **b_stack);
void	sort_stacks(t_stack **a_stack, t_stack **b_stack);

// errors
int		writing_errors(char *str);
int		duplicate(t_stack *stack, int n);
void	free_stack(t_stack **stack);
void	exit_error(t_stack **stack, char **split_argv, int flag);

// utils
long	ft_atol(const char *str);
t_stack	*high_number(t_stack *stack);
t_stack	*low_number(t_stack *stack);
void	free_split(char **str);
int		find_distance(t_stack **stack, int nb);
int		get_distance(t_stack **a_stack, int nb);
void	move_to_a_help(t_stack **a_stack, t_stack **b_stack, int index);
void	free_all(t_stack **stack, char **splitted);
void	check_mem(t_stack **stack, char **argv, int splitted);
void	check_args(int argc, char *argv[]);

// stacks
void	init_stack(t_stack **stack, char **argv, int splited);
int		verify(t_stack *stack);

//push_swap_utils
void	set_current_position(t_stack *stack);
void	set_target_node(t_stack *a_stack, t_stack *b_stack);
void	set_price(t_stack *a_stack, t_stack *b_stack);
void	set_cheapest(t_stack *b_stack);
t_stack	*return_cheapest(t_stack *stack);
void	rotate_both(t_stack **a_stack,
			t_stack **b_stack, t_stack *cheapest_node);
void	reverse_rotate_both(t_stack **a_stack,
			t_stack **b_stack, t_stack *cheapest_node);
void	rotation(t_stack **stack, t_stack *found_node, char stack_name);
void	init_nodes(t_stack *a_stack, t_stack *b_stack);
void	move_nodes(t_stack **a_stack, t_stack **b_stack);

#endif
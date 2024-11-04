/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:32 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:06:33 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_cheapest(t_stack *b_stack)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (!b_stack)
		return ;
	best_match_value = LONG_MAX;
	best_match_node = NULL;
	while (b_stack)
	{
		if (b_stack->cost < best_match_value)
		{
			best_match_value = b_stack->cost;
			best_match_node = b_stack;
		}
		b_stack = b_stack->next;
	}
	if (best_match_node)
		best_match_node->cheapest = true;
}

t_stack	*return_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack **a_stack,
					t_stack **b_stack, t_stack *cheapest_node)
{
	if (!a_stack || !(*a_stack) || !b_stack || !(*b_stack) || !cheapest_node)
		return ;
	while (*a_stack != cheapest_node->target && *b_stack != cheapest_node)
		rr(a_stack, b_stack);
	set_current_position(*a_stack);
	set_current_position(*b_stack);
}

void	reverse_rotate_both(t_stack **a_stack, t_stack **b_stack,
		t_stack *cheapest_node)
{
	if (!a_stack || !(*a_stack) || !b_stack || !(*b_stack) || !cheapest_node)
		return ;
	while (*a_stack != cheapest_node->target && *b_stack != cheapest_node)
		rrr(a_stack, b_stack);
	set_current_position(*a_stack);
	set_current_position(*b_stack);
}

void	rotation(t_stack **stack, t_stack *found_node, char stack_name)
{
	if (!stack || !(*stack) || !found_node)
		return ;
	while (*stack != found_node)
	{
		if (stack_name == 'a')
		{
			if (found_node->below_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (found_node->below_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

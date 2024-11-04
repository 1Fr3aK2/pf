/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:36 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 16:00:38 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_current_position(t_stack *stack)
{
	int	mid;

	if (!stack)
		return ;
	mid = ft_lstsize((t_list *)stack) / 2;
	while (stack)
	{
		if (stack->index <= mid)
			stack->below_median = true;
		else
			stack->below_median = false;
		stack = stack->next;
	}
}

void	set_target_node(t_stack *a_stack, t_stack *b_stack)
{
	t_stack	*current_a;
	long	best_match_number;

	if (!a_stack || !b_stack)
		return ;
	while (b_stack)
	{
		best_match_number = LONG_MAX;
		current_a = a_stack;
		while (current_a)
		{
			if (current_a->number > b_stack->number
				&& current_a->number < best_match_number)
			{
				best_match_number = current_a->number;
				b_stack->target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_number == LONG_MAX)
			b_stack->target = low_number(a_stack);
		b_stack = b_stack->next;
	}
}

static int	get_price(int position, int len, bool below_median)
{
	if (below_median == true)
		return (position);
	return (len - position);
}

static int	get_push_price(int price_a, int price_b, bool same_side)
{
	if (same_side == true)
	{
		if (price_a > price_b)
			return (price_a);
		return (price_b);
	}
	return (price_a + price_b);
}

void	set_price(t_stack *a_stack, t_stack *b_stack)
{
	int		len_b;
	int		price_a;
	int		price_b;
	int		len_a;
	bool	below_median;

	if (!a_stack || !b_stack)
		return ;
	len_a = ft_lstsize((t_list *)a_stack);
	len_b = ft_lstsize((t_list *)b_stack);
	while (b_stack)
	{
		price_b = get_price(b_stack->index, len_b, b_stack->below_median);
		price_a = get_price(b_stack->target->index, len_a,
				b_stack->target->below_median);
		below_median = (b_stack->below_median == b_stack->target->below_median);
		b_stack->cost = get_push_price(price_a, price_b, below_median);
		b_stack = b_stack->next;
	}
}

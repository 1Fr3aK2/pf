/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:05:14 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:08:06 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_nodes(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*cheapest_node;

	if (!a_stack || !b_stack)
		return ;
	cheapest_node = return_cheapest(*b_stack);
	if (cheapest_node->below_median && cheapest_node->target->below_median)
		rotate_both(a_stack, b_stack, cheapest_node);
	else if (!(cheapest_node->below_median)
		&& !(cheapest_node->target->below_median))
		reverse_rotate_both(a_stack, b_stack, cheapest_node);
	rotation(b_stack, cheapest_node, 'b');
	rotation(a_stack, cheapest_node->target, 'a');
	pa(b_stack, a_stack);
}

void	init_nodes(t_stack *a_stack, t_stack *b_stack)
{
	if (!a_stack || !b_stack)
		return ;
	set_current_position(a_stack);
	set_current_position(b_stack);
	set_target_node(a_stack, b_stack);
	set_price(a_stack, b_stack);
	set_cheapest(b_stack);
}

void	push_swap(t_stack **a_stack, t_stack **b_stack)
{
	t_stack		*smallest;
	int			len_a;

	if (!a_stack || !(*a_stack))
		return ;
	len_a = ft_lstsize((t_list *)*a_stack);
	while (len_a-- > 3)
		pb(a_stack, b_stack);
	sort_three(a_stack);
	while (*b_stack)
	{
		init_nodes(*a_stack, *b_stack);
		move_nodes(a_stack, b_stack);
	}
	set_current_position(*a_stack);
	smallest = low_number(*a_stack);
	if (smallest->below_median == true)
		while (*a_stack != smallest)
			ra(a_stack);
	else
		while (*a_stack != smallest)
			rra(a_stack);
}

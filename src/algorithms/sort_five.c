/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:05:24 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:05:24 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_five(t_stack **a_stack, t_stack **b_stack)
{
	int	distance;
	int	median;

	if (!a_stack || !(*a_stack))
		return ;
	distance = find_distance(a_stack, low_number(*a_stack)->number);
	median = ft_lstsize((t_list *)*a_stack) / 2;
	while (distance)
	{
		if (distance > median)
		{
			rra(a_stack);
			distance = find_distance(a_stack, low_number(*a_stack)->number);
		}
		else
		{
			ra(a_stack);
			distance = find_distance(a_stack, low_number(*a_stack)->number);
		}
	}
	if (verify(*a_stack) == 0)
		return ;
	pb(a_stack, b_stack);
	sort_four(a_stack, b_stack);
	pa(b_stack, a_stack);
}

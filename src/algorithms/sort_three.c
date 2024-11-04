/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:05:34 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:05:34 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*highest_number;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	highest_number = high_number(*stack);
	if ((*stack)->number == highest_number->number)
		ra(stack);
	if ((*stack)->next->number == highest_number->number)
		rra(stack);
	if ((*stack)->number > (*stack)->next->number)
		sa(stack);
}

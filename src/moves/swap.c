/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:18 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:06:18 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*temp;
	int		temp_index;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = (*stack);
	(*stack) = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
	temp->prev = (*stack);
	if (temp->next)
		temp->next->prev = temp;
	temp_index = (*stack)->index;
	(*stack)->index = temp->index;
	temp->index = temp_index;
}

void	sa(t_stack **a_stack)
{
	swap(a_stack);
	ft_printf("sa\n");
}

void	sb(t_stack **b_stack)
{
	swap(b_stack);
	ft_printf("sb\n");
}

void	ss(t_stack **a_stack, t_stack **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	ft_printf("ss\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:02 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:06:02 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	update_push_index(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*current_a;
	t_stack	*current_b;

	if (!a_stack || !(*a_stack) || !b_stack || !(*b_stack))
		return ;
	current_a = (*a_stack);
	while (current_a)
	{
		current_a->index--;
		current_a = current_a->next;
	}
	if ((*b_stack)->next != NULL)
	{
		current_b = (*b_stack)->next;
		while (current_b)
		{
			current_b->index++;
			current_b = current_b->next;
		}
	}
}

static void	push(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (!a_stack || !(*a_stack) || !b_stack)
		return ;
	temp_a = (*a_stack);
	(*a_stack) = (*a_stack)->next;
	if (*a_stack)
		(*a_stack)->prev = NULL;
	temp_a->prev = NULL;
	if (!(*b_stack))
	{
		(*b_stack) = temp_a;
		(*b_stack)->next = NULL;
	}
	else
	{
		temp_b = (*b_stack);
		(*b_stack) = temp_a;
		(*b_stack)->next = temp_b;
		temp_b->prev = temp_a;
	}
	update_push_index(a_stack, b_stack);
}

void	pa(t_stack **b_stack, t_stack **a_stack)
{
	push(b_stack, a_stack);
	ft_printf("pa\n");
}

void	pb(t_stack **a_stack, t_stack **b_stack)
{
	push(a_stack, b_stack);
	ft_printf("pb\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:13 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:06:13 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*lastnode;
	t_stack	*current;
	int		temp_index;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = (*stack);
	(*stack) = (*stack)->next;
	lastnode = (t_stack *)ft_lstlast((t_list *)*stack);
	(*stack)->prev = NULL;
	lastnode->next = temp;
	temp->prev = lastnode;
	temp->next = NULL;
	temp_index = lastnode->index;
	temp->index = temp_index;
	current = *stack;
	while (current)
	{
		if (current->number != temp->number)
			current->index--;
		else
			return ;
		current = current->next;
	}
}

void	ra(t_stack **a_stack)
{
	rotate(a_stack);
	ft_printf("ra\n");
}

void	rb(t_stack **b_stack)
{
	rotate(b_stack);
	ft_printf("rb\n");
}

void	rr(t_stack **a_stack, t_stack **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	ft_printf("rr\n");
}

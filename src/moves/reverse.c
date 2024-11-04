/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:08 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:06:08 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*lastnode;
	t_stack	*current;
	int		temp_index;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	lastnode = (t_stack *)ft_lstlast((t_list *)*stack);
	if (lastnode->prev)
		lastnode->prev->next = NULL;
	temp = (*stack);
	(*stack) = lastnode;
	lastnode->next = temp;
	lastnode->prev = NULL;
	temp->prev = lastnode;
	temp_index = temp->index;
	lastnode->index = temp_index;
	current = (*stack)->next;
	while (current)
	{
		current->index++;
		current = current->next;
	}
}

void	rra(t_stack **a_stack)
{
	reverse(a_stack);
	ft_printf("rra\n");
}

void	rrb(t_stack **b_stack)
{
	reverse(b_stack);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a_stack, t_stack **b_stack)
{
	reverse(a_stack);
	reverse(b_stack);
	ft_printf("rrr\n");
}

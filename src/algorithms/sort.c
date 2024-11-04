/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:16:08 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 17:46:02 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stacks(t_stack **a_stack, t_stack **b_stack)
{
	int	size;

	if (!a_stack || !(*a_stack))
		return ;
	size = ft_lstsize((t_list *)*a_stack);
	if (size == 2)
		sa(a_stack);
	else if (size == 3)
		sort_three(a_stack);
	else if (size == 4)
		sort_four(a_stack, b_stack);
	else if (size == 5)
		sort_five(a_stack, b_stack);
	else
		push_swap(a_stack, b_stack);
}

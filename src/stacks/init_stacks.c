/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:26 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:06:26 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_stack(t_stack **stack, char **argv, int splitted)
{
	t_stack		*last;
	t_stack		*node;
	long		number;
	int			index;
	int			i;

	last = NULL;
	i = 0;
	index = 0;
	while (argv[i])
	{
		if (writing_errors(argv[i]))
			check_mem(stack, argv, splitted);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			check_mem(stack, argv, splitted);
		if (duplicate(*stack, (int)number))
			check_mem(stack, argv, splitted);
		node = (t_stack *)ft_lstnew(number, &index);
		if (!node)
			exit_error(stack, argv, 0);
		ft_lstadd_back((t_list **)stack, (t_list **)&last, (t_list *)node);
		i++;
	}
}

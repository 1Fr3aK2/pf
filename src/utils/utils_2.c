/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:41 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:06:42 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_distance(t_stack **stack, int nb)
{
	t_stack	*current;
	int		distance;

	if (!(stack) || !(*stack))
		return (-1);
	current = (*stack);
	distance = 0;
	while (current)
	{
		if (current->number == nb)
			return (distance);
		else
		{
			distance++;
			current = current->next;
		}
	}
	return (distance);
}

int	get_distance(t_stack **stack, int nb)
{
	t_stack	*current;
	int		distance;

	if (!(stack) || !(*stack))
		return (-1);
	current = (*stack);
	distance = 0;
	while (current)
	{
		if (nb > current->number)
		{
			distance++;
			current = current->next;
		}
		else
			break ;
	}
	return (distance);
}

void	free_all(t_stack **stack, char **splitted)
{
	free_stack(stack);
	free_split(splitted);
}

void	check_args(int argc, char *argv[])
{
	if (argc < 2)
		exit(1);
	if (argc == 2 && argv[1][0] == '\0')
		exit_error(NULL, NULL, 0);
}

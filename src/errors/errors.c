/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:05:51 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:05:51 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	writing_errors(char *str)
{
	if (!str || *str == '\0')
		return (1);
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if (*str == '+' || *str == '-')
	{
		str++;
		if (!(*str >= '0' && (*str) <= '9'))
			return (1);
	}
	else if (*str < '0' && *str > '9')
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	duplicate(t_stack *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->number == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	exit_error(t_stack **stack, char **split_argv, int flag)
{
	if (flag == 0)
		write(2, "Error\n", 6);
	if (stack)
		free_stack(stack);
	if (split_argv)
		free_split(split_argv);
	exit(1);
}

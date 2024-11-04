/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:46 by raamorim          #+#    #+#             */
/*   Updated: 2024/10/31 14:06:46 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	ft_atol(const char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	if (!str)
		return (-1);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	return (number * sign);
}

int	verify(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack	*high_number(t_stack *stack)
{
	t_stack	*highest_number;

	if (!stack)
		return (NULL);
	highest_number = stack;
	while (stack)
	{
		if (stack->number > highest_number->number)
			highest_number = stack;
		stack = stack->next;
	}
	return (highest_number);
}

t_stack	*low_number(t_stack *stack)
{
	t_stack	*lowest_number;

	if (!stack)
		return (NULL);
	lowest_number = stack;
	while (stack)
	{
		if (stack->number < lowest_number->number)
			lowest_number = stack;
		stack = stack->next;
	}
	return (lowest_number);
}

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

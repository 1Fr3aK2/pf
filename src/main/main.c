/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:33:58 by raamorim          #+#    #+#             */
/*   Updated: 2024/11/04 16:24:32 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		splited;
	char	**split_argv;

	a_stack = NULL;
	b_stack = NULL;
	split_argv = NULL;
	splited = 0;
	if (argc < 2)
		exit(1);
	if (argc == 2 && argv[1][0] == '\0')
		exit_error(NULL, NULL, 0);
	if (argc == 2 && argv[1][0] != '\0')
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv || !split_argv[0])
			exit_error(NULL, split_argv, 0);
		splited = 1;
		argv = split_argv;
	}
	else
		argv++;
	init_stack(&a_stack, argv, splited);
	if (verify(a_stack) == 1)
		sort_stacks(&a_stack, &b_stack);
	free_all(&a_stack, split_argv);
}

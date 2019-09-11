/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:39:13 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/09/11 08:51:12 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** for testing-- delete later
*/

void	ft_print_stacks(t_stacks *stacks)
{
	int i;

	i = 0;
	ft_putendl("stack a:");
	while (i < stacks->size_a)
	{
		ft_putnbr(stacks->stack_a[i++]);
		ft_putchar('\n');
	}
	i = 0;
	ft_putendl("stack b:");
	while (i < stacks->size_b)
	{
		ft_putnbr(stacks->stack_b[i++]);
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	t_stacks *stacks;

	if (argc > 1)
	{
		stacks = (t_stacks *)malloc(sizeof(t_stacks));
		check_args(stacks, argv, argc);
		sort(stacks);
		free_stacks(&stacks);
	}
	return (0);
}

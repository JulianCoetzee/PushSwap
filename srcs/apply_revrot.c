/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_revrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:45:45 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/09/11 08:17:34 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rra(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->size_a < 2)
		return ;
	i = stacks->size_a - 1;
	tmp = stacks->stack_a[i];
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = tmp;
	ft_putstr("rra\n");
}

void	apply_rrb(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->size_b < 2)
		return ;
	i = stacks->size_b - 1;
	tmp = stacks->stack_b[i];
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = tmp;
	ft_putstr("rrb\n");
}

void	apply_rrr(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->size_a > 1)
	{
		i = stacks->size_a - 1;
		tmp = stacks->stack_a[i];
		while (i-- > 0)
			stacks->stack_a[i + 1] = stacks->stack_a[i];
		stacks->stack_a[0] = tmp;
	}
	if (stacks->size_b > 1)
	{
		i = stacks->size_b - 1;
		tmp = stacks->stack_b[i];
		while (i > 0)
		{
			stacks->stack_b[i] = stacks->stack_b[i - 1];
			i--;
		}
		stacks->stack_b[0] = tmp;
	}
	ft_putstr("rrr\n");
}

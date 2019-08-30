/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_revrot_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:45:56 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/08/30 14:19:50 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rra_ch(t_stacks *stacks)
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
}

void	apply_rrb_ch(t_stacks *stacks)
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
}

void	apply_rrr_ch(t_stacks *stacks)
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
}

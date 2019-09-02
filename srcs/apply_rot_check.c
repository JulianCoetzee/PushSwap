/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rot_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:46:21 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/09/02 10:39:49 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_ra_ch(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->size_a < 2)
		return ;

	i = 1;
	tmp = stacks->stack_a[0];
	while (i < stacks->size_a)
	{
		stacks->stack_a[i - 1] = stacks->stack_a[i];
		i++;
	}
	stacks->stack_a[i - 1] = tmp;
}

void	apply_rb_ch(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->size_b < 2)
		return ;

	i = 1;
	tmp = stacks->stack_b[0];
	while (i < stacks->size_b)
	{
		stacks->stack_b[i - 1] = stacks->stack_b[i];
		i++;
	}
	stacks->stack_b[i - 1] = tmp;
}

void	apply_rr_ch(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->size_a > 1)
	{
		i = 1;
		tmp = stacks->stack_a[0];
		while (i++ < stacks->size_a)
		{
			stacks->stack_a[i - 1] = stacks->stack_a[i];
			i++;
		}
		stacks->stack_a[i - 1] = tmp;
	}
	if (stacks->size_b < 1)
	{
		i = 1;
		tmp = stacks->stack_b[0];
		while (i++ < stacks->size_b)
		{
			stacks->stack_b[i - 1] = stacks->stack_b[i];
			i++;
		}
		stacks->stack_b[i - 1] = tmp;
	}
}

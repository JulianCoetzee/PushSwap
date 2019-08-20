/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:45:34 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/08/20 13:39:26 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_ra(t_stacks *stacks)
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
	ft_putstr("ra\n");
}

void	apply_rb(t_stacks *stacks)
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
	ft_putstr("rb\n");
}

void	apply_rr(t_stacks *stacks)
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
	ft_putstr("rr\n");
}

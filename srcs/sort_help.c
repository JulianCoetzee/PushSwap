/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:43:49 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/09/11 08:56:08 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(int *stack, int size)
{
	int i;
	int mi;
	int min;

	i = 0;
	mi = 0;
	min = stack[i];
	while (i < size)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			mi = i;
		}
		i++;
	}
	return (mi);
}

int		find_max(int *stack, int size)
{
	int i;
	int mi;
	int max;

	i = 0;
	mi = 0;
	max = stack[i];
	while (i < size)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			mi = i;
		}
		i++;
	}
	return (mi);
}

void	min_first(t_stacks *stacks)
{
	int min;

	min = find_min(stacks->stack_a, stacks->size_a);
	if (min <= stacks->size_a / 2)
	{
		while (min--)
			apply_ra(stacks);
	}
	else
	{
		while ((stacks->size_a - min++) > 0)
			apply_rra(stacks);
	}
}

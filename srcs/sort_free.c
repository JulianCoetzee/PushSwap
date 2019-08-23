/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:47:07 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/08/05 14:34:11 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	sort_3(t_stacks *stacks)
{
	int max_i;

	if (stacks->size_a == 2)
	{
		apply_sa(stacks);
		return ;
	}
	max_i = find_max(stacks->stack_a, stacks->size_a);
	if (max_i == 0)
		apply_ra(stacks);
	if (max_i == 1)
		apply_rra(stacks);
	if (stacks->stack_a[0] > stacks->stack_a[1])
		apply_sa(stacks);
}

void	sort(t_stacks *stacks)
{
	if (is_sorted(stacks->stack_a, stacks->size_a) && stacks->size_b == 0)
		return ;
	if (stacks->size_a == 3)
		return (sort_3(stacks));
	else
		large_sort(stacks);
}

void	free_stacks(t_stacks stacks)
{
	if (stacks->stack_a)
		free(stacks->stack_a);
	if (stacks->stack_b)
		free(stacks->stack_b);
	if (stacks)
	{
		free(stacks);
		stacks = NULL;
	}
}

void	free_moves(t_moves *moves)
{
	free(moves->rot_a);
	free(moves->rot_b);
	free(moves->rot_c);
	free(moves);
	moves = NULL;
}

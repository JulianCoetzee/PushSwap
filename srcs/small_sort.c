/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:41:09 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/09/02 10:44:40 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

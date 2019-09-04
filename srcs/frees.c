/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:47:07 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/09/04 11:04:29 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(int *stack, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_stacks(t_stacks **stacks)
{
	if ((*stacks)->stack_a)
		free((*stacks)->stack_a);
	if ((*stacks)->stack_b)
		free((*stacks)->stack_b);
	if (*stacks)
	{
		free(*stacks);
		*stacks = NULL;
	}
}

void	free_moves(t_moves **moves)
{
	free((*moves)->rot_a);
	free((*moves)->rot_b);
	free((*moves)->rot_c);
	free(*moves);
	*moves = NULL;
}

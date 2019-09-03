/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   least_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:49:53 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/09/03 11:35:19 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_place_b(int *stack, int size, int elem, char **rot)
{
	int i;
	int place;

	i = 0;
	place = 0;
	if (size == 2 && elem > stack [0] && elem < stack[1])
		place = 0;
	else if (size == 2 && elem < stack [0] && elem > stack[1])
		place = 1;
	else if (elem > stack[find_max(stack, size)] || elem < stack[find_min(stack, size)])
		place = find_min(stack, size);
	else
	{
		while (i < size)
		{
			if (elem > stack[i] && ((i + 1 < size && elem < stack[i + 1]) ||
							(i + 1 == size && elem < stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	}
	return (find_rot_a(size, place, rot));
}

static int	(find_common(t_moves *moves))
{
	int c;

	c = 0;
	if (((ft_strequ(moves->rot_a, "rra") && ft_strequ(moves->rot_b, "rrb"))) ||
			(ft_strequ(moves->rot_a, "ra") && ft_strequ(moves->rot_b, "rb")))
	{
		c = (moves->a_moves > moves->b_moves ? moves->b_moves : moves->a_moves);
		if (c)
		{
			moves->rot_c = ft_strcpy(moves->rot_c, moves->rot_a);
			moves->rot_c[ft_strlen(moves->rot_c) - 1] = 'r';
			moves->b_moves = moves->b_moves - c;
			moves->a_moves = moves->a_moves - c;
		}
	}
	return (c);
}

static t_moves	*calc_moves_a_to_b(t_stacks *stacks, int pos)
{
	t_moves *moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->rot_a = ft_strnew(3);
	moves->rot_b = ft_strnew(3);
	moves->rot_c = ft_strnew(3);
	moves->elem = stacks->stack_a[pos];
	moves->a_moves = find_rot_a(stacks->size_a, pos, &(moves->rot_a));
	moves->b_moves = find_place_b(stacks->stack_b, stacks->size_b,
			stacks->stack_a[pos], &(moves->rot_b));
	moves->c_moves = find_common(moves);
	moves->total = moves->a_moves + moves->b_moves + moves->c_moves + 1;
	return (moves);
}

t_moves	*least_moves_a_to_b(t_stacks *stacks)
{
	int i;
	t_moves *least;
	t_moves *moves;

	i = 0;
	while (i < stacks->size_a)
	{
		moves = calc_moves_a_to_b(stacks, i);
		if (i == 0)
			least = moves;
		else if (least->total > moves->total)
		{
			free_moves(&least);
			least = moves;
		}
		else
			free_moves(&moves);
		i++;
	}
	return (least);
}

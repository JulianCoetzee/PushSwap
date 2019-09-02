/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:37:49 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/09/02 10:27:23 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_place_in_a(int *stack, int size, int elem, char **rot_type)
{
	int i;
	int place;

	i = 0;
	place = 0;
	if (size == 2 && elem > stack [0] && elem < stack[1])
		place = 1;
	else if (size == 2 && elem < stack [0] && elem > stack[1])
		place = 0;
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
	return (find_rot_a(size, place, rot_type));
}

static void	push_back(t_stacks *stacks)
{
	int rotn;
	char *rot_type;

	rotn = 0;
	ft_strnew(3);
	while (stacks->stack_b)
	{
		rotn = find_place_in_a(stacks->stack_a, stacks->size_a, 
				stacks->stack_b[0], &rot_type);
		while (rotn > 0)
		{
			if (ft_strequ(rot_type, "ra"))
				apply_ra(stacks);
			else
				apply_rra(stacks);
			rotn--;
		}
		apply_pa(stacks);
	}
	min_first(stacks);
	free(rot_type);
}

static void	push_remainder(t_stacks *stacks)
{
	int i;

	i  = 0;
	while (stacks->size_a > 2)
	{
		i = find_min(stacks->stack_a, stacks->size_a);
		if (i == 0)
			apply_pb(stacks);
		else if (i <= stacks->size_a / 2)
			apply_ra(stacks);
		else if (i > stacks->size_a / 2)
			apply_rra(stacks);
	}
}

static void	do_moves(t_moves *moves, t_stacks *stacks)
{
	while (moves->a_moves)
	{
		if (ft_strequ(moves->rot_a, "ra"))
			apply_ra(stacks);
		else
			apply_rra(stacks);
		moves->a_moves--;
	}
	while (moves->b_moves)
	{
		if (ft_strequ(moves->rot_b, "rb"))
			apply_rb(stacks);
		else
			apply_rrb(stacks);
		moves->b_moves--;
	}
}

void	large_sort(t_stacks *stacks)
{
	t_moves *best_moves;
	int optimal;

	optimal = (stacks->size_a > 200) ? 50 : 2;
	while (stacks->size_b != 2)
		apply_pb(stacks);
	while (stacks->size_a > optimal)
	{
		best_moves = least_moves_a_to_b(stacks);
		while (best_moves->c_moves)
		{
			if(ft_strequ(best_moves->rot_c, "rr"))
				apply_rr(stacks);
			else
				apply_rra(stacks);
			best_moves->c_moves--;
		}
		do_moves(best_moves, stacks);
		apply_pb(stacks);
		free_moves(&best_moves);
	}
	push_remainder(stacks);
	push_back(stacks);
}

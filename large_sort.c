/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:37:49 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/08/05 14:50:42 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_place_in_a(*int stack, int size, int elem, char rot_type)
{
	int i;
	int place;

	i = 0;
	place = 0;
	if (size == 2 && elem > stack [0] && elem < stack[1])
		place = 1;
	else if (size == 2 && elem < stack [0] && elem > stack[1])
		place = 0;
	else if (elem > stack[find_max(stacks, size)] || elem < stack[find_min(stack, size)])
		place = find_min(stack, size);
	else
	{
		while (i < size)
		{
			if (elem > stack[i] && ((i + 1 < size && elem < stack[i + 1] ||
							i + 1 == size && elem < stack[0])))
					{
					place = i + 1;
					break ;
					}
					i++;
		}
	}
		return (find_rot_a(sie, place, rot_type));
}

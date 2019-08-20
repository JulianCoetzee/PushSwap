/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:49:19 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/08/20 14:04:22 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_rot_a(int len, int pos, char **rot)
{
	if (pos > len / 2)
	{
		*rot = ft_strcpy(*rot, "rra");
		if (len > 2)
			pos = len - pos;
	}
	else
		*rot = ft_strcpy(*rot, "ra");
	return (pos);
}

int find_rot_b(int len, int pos, char **rot)
{
	if (pos > len / 2)
	{
		*rot = ft_strcpy(*rot, "rrb");
		if (len > 2)
			pos = len - pos;
	}
	else
		*rot = ft_strcpy(*rot, "rb");
	return (pos);
}

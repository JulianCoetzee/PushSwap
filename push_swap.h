/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:59:40 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/07/25 13:01:10 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stacks
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
}			t_stacks;

typedef	struct	s_moves
{
	int		a_moves;
	int		b_moves;
	int		c_moves;
	int		total;
	int		elem;
	char	rot_a;
	char	rot_b;
	char	rot_c;
}			t_moves;


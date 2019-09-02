/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:38:44 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/09/02 10:38:30 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_rr(t_stacks *stacks, char *ins)
{
	if (ins[2] == '\0')
		apply_rr_ch(stacks);
	else if (ins[2] == 'a' && ins[3] == '\0')
		apply_rra_ch(stacks);
	else if (ins[2] == 'b' && ins[3] == '\0')
		apply_rrb_ch(stacks);
	else if (ins[2] == 'r' && ins[3] == '\0')
		apply_rrr_ch(stacks);
	else
		return (-1);
	return (0);
}

static int	do_ins(t_stacks *stacks, char *ins)
{
	if (ft_strnequ(ins, "rr", 2))
	{
		if (do_rr(stacks, ins))
			return (-1);
	}

	else if (ft_strequ(ins, "sa"))
		apply_sa_ch(stacks);
	else if (ft_strequ(ins, "sb"))
		apply_sb_ch(stacks);
	else if (ft_strequ(ins, "ss"))
		apply_ss_ch(stacks);
	else if (ft_strequ(ins, "pa"))
		apply_pa_ch(stacks);
	else if (ft_strequ(ins, "pb"))
		apply_pb_ch(stacks);
	else if (ft_strequ(ins, "ra"))
		apply_ra_ch(stacks);
	else if (ft_strequ(ins, "rb"))
		apply_rb_ch(stacks);
	else
		return (-1);
	return (0);
}

static void	get_ins(t_stacks *stacks)
{
	char *ins;

	ins = NULL;
	while (get_next_line(0, &ins) > 0)
	{
		if (do_ins(stacks, ins))
		{
			ft_putstr_fd("Error\n", 2);
			free_stacks(&stacks);
			ft_strdel(&ins);
			exit(1);
		}
		ft_strdel(&ins);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if(argc > 1)
	{
		stacks = (t_stacks *)malloc(sizeof(t_stacks));
		check_args(stacks, argv, argc);
		get_ins(stacks);
		if (is_sorted(stacks->stack_a, stacks->size_a) &&
				stacks->size_b == 0)
		{
			ft_putstr("OK\n");
		}
		else
			ft_putstr("KO\n");
		free_stacks(&stacks);
	}
	return (0);
}

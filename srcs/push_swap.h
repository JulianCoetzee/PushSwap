/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:59:40 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/08/30 15:03:17 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483648

typedef struct	s_stacks
{
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
}				t_stacks;

typedef	struct	s_moves
{
	int			a_moves;
	int			b_moves;
	int			c_moves;
	int			total;
	int			elem;
	char		*rot_a;
	char		*rot_b;
	char		*rot_c;
}				t_moves;

/*
** void		ft_printstacks(t_stacks *stacks);
*/
/*
** build_stacks.c
*/
void			check_args(t_stacks *stacks, char **av, int ac);
/*
** sort_free.c
*/
int				is_sorted(int *stack, int size);
void			free_stacks(t_stacks *stacks);
void			free_moves(t_moves *moves);
void			sort(t_stacks *stacks);
/*
** large_sort.c
*/
void			large_sort(t_stacks *stacks);
/*
** apply_instruct.c
*/
void			apply_sa(t_stacks *stacks);
void			apply_sb(t_stacks *stacks);
void			apply_ss(t_stacks *stacks);
void			apply_pa(t_stacks *stacks);
void			apply_pb(t_stacks *stacks);
/*
** apply_instruct_check.c
*/
void			apply_sa_ch(t_stacks *stacks);
void			apply_sb_ch(t_stacks *stacks);
void			apply_ss_ch(t_stacks *stacks);
void			apply_pa_ch(t_stacks *stacks);
void			apply_pb_ch(t_stacks *stacks);
/*
** sort_help.c
*/
int				find_max(int *stack, int size);
int				find_min(int *stack, int size);
void			min_first(t_stacks *stacks);
/*
** apply_rot.c
*/
void			apply_ra(t_stacks *stacks);
void			apply_rb(t_stacks *stacks);
void			apply_rr(t_stacks *stacks);
/*
** apply_revrot.c
*/
void			apply_rra(t_stacks *stacks);
void			apply_rrb(t_stacks *stacks);
void			apply_rrr(t_stacks *stacks);
/*
** apply_rot_check.c
*/
void			apply_ra_ch(t_stacks *stacks);
void			apply_rb_ch(t_stacks *stacks);
void			apply_rr_ch(t_stacks *stacks);
/*
** apply_revrot_check.c
*/
void			apply_rra_ch(t_stacks *stacks);
void			apply_rrb_ch(t_stacks *stacks);
void			apply_rrr_ch(t_stacks *stacks);
/*
** find_rot.c
*/
int				find_rot_a(int len, int pos, char **rot);
int				find_rot_b(int len, int pos, char **rot);
/*
** least_moves.c
*/
t_moves			*least_moves_a_to_b(t_stacks *stacks);

#endif

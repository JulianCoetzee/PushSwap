/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:51:03 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/08/28 10:16:45 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate _in(char **split, char nbr, int start)
{
	int i;

	i = 0;
	if (nbr[i] == '-' || nbr == '+')
	{
		if (!(ft_isdigit(nbr[i + 1])))
			return (0);
		i++;
	}
	while(nbr && nbr[i] != '\0')
	{
		if (!(ft_isdigit(nbr[i])))
			return (0);
		i++;
	}
	if (ft_atoll(nbr) > MAX_INT || ft_atoll(nbr) < MIN_INT)
		return (0);
	while (split[start] && split && nbr)
	{
		if (ft_strequ(split[start], nbr))
			return (0);
		start++;
	}
	return (1);
}

static void 	free_split(char **split)
{
	int i;

	i = 0;
	if (*split)
	{
		while ((*split)[i])
			free(*split[i++]);
		free(*split);
		*split = NULL;
	}
}

static int	split_count(char *split)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (*split[i++])
		count++;
	return (count);
}

static int	build_stacks(t_stacks *stacks, char **split, int count)
{
	int i;

	i = -1;

	stacks->stack_a = (int *)malloc(sizeof(int) * count);
	stacks->stack_b = (int *)malloc(sizeof(int) * count);
	stacks->size_a = count;
	stacks_size_b = 0;
	while(++i < count)
	{
		if (validat_in(split, split[i], i + 1))
			stacks->stack_a[i] = ft_atoi(split[i]);
		else
		{
			free_stacks(&stacks);
			ft_putstr_fd("Erro\n", 2);
			return (0);
		}
	}
	return (1);
}

void check_args(t_stacks *stacks, char **av, int ac)
{
	char **spliti;

	split = NULL;
	if (ac == 2)
	{
		split = ft_strsplit(av[1], ' ');
		if (!build_stacks(stacks, (av + 1), (ac - 1)))
		{
			free_split(&split);
			exit(1);
		}
		free_split(&split);
	}
	else if (!build_stacks(stacks, (av + 1), ac-1))
		exit(1);
	return ;
}

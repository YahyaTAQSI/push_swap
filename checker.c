/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:26:08 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/22 15:32:47 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	do_instructions(t_all *all, char *s)
{
	if (!ft_strcmp(s, "sa\n"))
		ft_sa(&all, 0);
	else if (!ft_strcmp(s, "sb\n"))
		ft_sb(&all, 0);
	else if (!ft_strcmp(s, "ss\n"))
		ft_ss(&all, 0);
	else if (!ft_strcmp(s, "pa\n"))
		ft_pusha(&all, 0);
	else if (!ft_strcmp(s, "pb\n"))
		ft_pushb(&all, 0);
	else if (!ft_strcmp(s, "ra\n"))
		ft_rotatea(&all, 0);
	else if (!ft_strcmp(s, "rb\n"))
		ft_rotateb(&all, 0);
	else if (!ft_strcmp(s, "rr\n"))
		ft_rotateab(&all, 0);
	else if (!ft_strcmp(s, "rra\n"))
		ft_reversea(&all, 0);
	else if (!ft_strcmp(s, "rrb\n"))
		ft_reverseb(&all, 0);
	else if (!ft_strcmp(s, "rrr\n"))
		ft_reverseab(&all, 0);
	else
		return (write(1, "Error\n", 6), exit(1));
}

int	sort_and_size(t_all *all)
{
	t_list	*head;
	t_list	*nextt;

	head = all->heada;
	nextt = all->heada->next;
	while (1)
	{
		if (head->content > nextt->content)
			return (0);
		head = head->next;
		nextt = nextt->next;
		if (nextt == all->lheada)
			break ;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_all	all;
	char	*s;

	ft_parcing(ac, av, &all);
	s = get_next_line(0);
	while (s)
	{
		do_instructions(&all, s);
		free(s);
		s = get_next_line(0);
	}
	if (sort_and_size(&all))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&all.heada);
	return (0);
}

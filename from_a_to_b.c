/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:58:58 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/22 15:21:54 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexb(t_all *all)
{
	int		i;

	if (all->bsize == 0)
		return ;
	i = 0;
	while (all->headb)
	{
		all->headb->key = i++;
		all->headb = all->headb->next;
		if (all->lheadb == all->headb)
			break ;
	}
}

t_list	*whichone(t_all *all, int *cp)
{
	t_list	*head;
	t_list	*next;
	int		curr;

	head = all->heada->prev;
	next = all->heada;
	while (1)
	{
		curr = all->headb->content;
		if ((curr > head->content && curr < next->content)
			|| (head->content > next->content
				&& (curr > head->content || curr < next->content)))
			return (all->headb);
		(*cp)++;
		next = next->next;
		head = head->next;
		if (next == all->lheada)
			return (NULL);
	}
}

void	siri_l_a(t_all *all, t_moves allmoves)
{
	while (allmoves.besta > 0 && allmoves.bestb > 0)
	{
		ft_rotateab(&all, 1);
		allmoves.besta--;
		allmoves.bestb--;
	}
	while (allmoves.besta < 0 && allmoves.bestb < 0)
	{
		ft_reverseab(&all, 1);
		allmoves.besta++;
		allmoves.bestb++;
	}
	siri_l_a2(all, allmoves);
}

void	thebestone(t_all *all)
{
	t_moves	allmoves;

	while (all->bsize > 0)
	{
		indexb(all);
		allmoves.moves = all->size + all->bsize;
		while (1)
		{
			checkwhichone(all, &allmoves);
			if (allmoves.movea >= 0 && allmoves.moveb >= 0)
				checksign(&allmoves);
			else if (allmoves.movea < 0 && allmoves.moveb < 0)
				checksign(&allmoves);
			else if (ft_abs(allmoves.movea)
				+ ft_abs(allmoves.moveb) <= allmoves.moves)
				checksign2(&allmoves);
			all->headb = all->headb->next;
			if (all->lheadb == all->headb)
				break ;
		}
		siri_l_a(all, allmoves);
		ft_pusha(&all, 1);
	}
}

void	rja3_lblastk(t_all *all)
{
	int	min;
	int	cp;
	int	cp2;

	cp = 0;
	min = INT_MAX;
	while (all->heada)
	{
		if (all->heada->content <= min)
		{
			min = all->heada->content;
			cp2 = cp;
		}
		all->heada = all->heada->next;
		cp++;
		if (all->lheada == all->heada)
			break ;
	}
	if (cp2 > all->size / 2)
		cp2 -= all->size;
	rja3_lblastk2(all, &cp2);
}

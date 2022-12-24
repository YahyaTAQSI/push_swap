/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:48:47 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/22 12:44:18 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkwhichone(t_all *all, t_moves *allmoves)
{
	t_list	*tmp;

	allmoves->movea = 0;
	tmp = whichone(all, &allmoves->movea);
	allmoves->moveb = tmp->key;
	if (allmoves->movea > all->size / 2)
		allmoves->movea -= all->size;
	if (allmoves->moveb > all->bsize / 2)
		allmoves->moveb -= all->bsize;
}

void	checksign(t_moves *allmoves)
{
	int		itmp;

	if (ft_abs(allmoves->movea) >= ft_abs(allmoves->moveb))
		itmp = ft_abs(allmoves->movea);
	else
		itmp = ft_abs(allmoves->moveb);
	if (itmp <= allmoves->moves)
	{
		allmoves->moves = itmp;
		allmoves->besta = allmoves->movea;
		allmoves->bestb = allmoves->moveb;
	}
}

void	checksign2(t_moves *allmoves)
{
	allmoves->moves = ft_abs(allmoves->movea) + ft_abs(allmoves->moveb);
	allmoves->besta = allmoves->movea;
	allmoves->bestb = allmoves->moveb;
}

void	rja3_lblastk2(t_all *all, int *cp2)
{
	while ((*cp2) > 0)
	{
		ft_rotatea(&all, 1);
		(*cp2)--;
	}
	while ((*cp2) < 0)
	{
		ft_reversea(&all, 1);
		(*cp2)++;
	}
	all->headb = NULL;
	all->lheadb = NULL;
	ft_lstclear(&all->heada);
}

void	siri_l_a2(t_all *all, t_moves allmoves)
{
	while (allmoves.besta > 0)
	{
		ft_rotatea(&all, 1);
		allmoves.besta--;
	}
	while (allmoves.besta < 0)
	{
		ft_reversea(&all, 1);
		allmoves.besta++;
	}
	while (allmoves.bestb > 0)
	{
		ft_rotateb(&all, 1);
		allmoves.bestb--;
	}
	while (allmoves.bestb < 0)
	{
		ft_reverseb(&all, 1);
		allmoves.bestb++;
	}
}

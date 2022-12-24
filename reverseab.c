/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:29:39 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/22 11:59:08 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reversea(t_all **all, int prntbl)
{
	if ((*all)->size < 2)
		return ;
	(*all)->heada = (*all)->heada->prev;
	(*all)->lheada = (*all)->heada;
	if (prntbl)
		write(1, "rra\n", 4);
}

void	ft_reverseb(t_all **all, int prntbl)
{
	if ((*all)->bsize < 2)
		return ;
	(*all)->headb = (*all)->headb->prev;
	(*all)->lheadb = (*all)->headb;
	if (prntbl)
		write(1, "rrb\n", 4);
}

void	ft_reverseab(t_all **all, int prntbl)
{
	ft_reversea(all, 0);
	ft_reverseb(all, 0);
	if (prntbl)
		write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:46:44 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/22 15:14:03 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotatea(t_all **all, int prntbl)
{
	if ((*all)->size < 2)
		return ;
	(*all)->heada = (*all)->heada->next;
	(*all)->lheada = (*all)->heada;
	if (prntbl)
		write(1, "ra\n", 3);
}

void	ft_rotateb(t_all **all, int prntbl)
{
	if ((*all)->bsize < 2)
		return ;
	(*all)->headb = (*all)->headb->next;
	(*all)->lheadb = (*all)->headb;
	if (prntbl)
		write(1, "rb\n", 3);
}

void	ft_rotateab(t_all **all, int prntbl)
{
	ft_rotatea(all, 0);
	ft_rotateb(all, 0);
	if (prntbl)
		write(1, "rr\n", 3);
}

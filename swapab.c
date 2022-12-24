/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   swapab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:36:13 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/21 11:32:21 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_all **all, int prntbl)
{
	t_list	*tmp;

	if ((*all)->size < 2)
		return ;
	tmp = (*all)->heada->next;
	(*all)->heada->next = tmp->next;
	tmp->next->prev = (*all)->heada;
	tmp->next = (*all)->heada;
	(*all)->lheada = tmp;
	tmp->prev = (*all)->heada->prev;
	(*all)->heada->prev->next = tmp;
	(*all)->heada->prev = tmp;
	(*all)->heada = tmp;
	if (prntbl)
		write(1, "sa\n", 3);
}

void	ft_sb(t_all **all, int prntbl)
{
	t_list	*tmp;

	if ((*all)->bsize < 2)
		return ;
	tmp = (*all)->headb->next;
	(*all)->headb->next = tmp->next;
	tmp->next->prev = (*all)->headb;
	tmp->next = (*all)->headb;
	(*all)->lheadb = tmp;
	tmp->prev = (*all)->headb->prev;
	(*all)->headb->prev->next = tmp;
	(*all)->headb->prev = tmp;
	(*all)->headb = tmp;
	if (prntbl)
		write(1, "sb\n", 3);
}

void	ft_ss(t_all **all, int prntbl)
{
	ft_sa(all, 0);
	ft_sb(all, 0);
	if (prntbl)
		write(1, "ss\n", 3);
}

int	fakeswap(t_all *all)
{
	int	tlic;

	tlic = all->plic;
	ft_sa(&all, 0);
	all->lic = 0;
	all->plic = 0;
	ft_besthead(all, &all->lic, &all->plic);
	if (all->plic > tlic)
	{
		write(1, "sa\n", 3);
		return (1);
	}
	else
	{
		all->lic = 0;
		all->plic = 0;
		ft_sa(&all, 0);
		ft_besthead(all, &all->lic, &all->plic);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:33:51 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/22 15:21:23 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushb(t_all **all, int prntbl)
{
	t_list	*tmp;

	if ((*all)->size == 0)
		return ;
	tmp = (*all)->heada->next;
	tmp->prev = (*all)->heada->prev;
	(*all)->heada->prev->next = tmp;
	ft_lstadd_front(&(*all)->headb, (*all)->heada);
	(*all)->heada = tmp;
	(*all)->lheada = tmp;
	(*all)->lheadb = (*all)->headb;
	if ((*all)->heada && prntbl)
		write(1, "pb\n", 3);
	(*all)->bsize++;
	(*all)->size--;
}

void	ft_pusha(t_all **all, int prntbl)
{
	t_list	*tmp;

	if ((*all)->bsize == 0)
		return ;
	tmp = (*all)->headb->next;
	tmp->prev = (*all)->headb->prev;
	(*all)->headb->prev->next = tmp;
	ft_lstadd_front(&(*all)->heada, (*all)->headb);
	(*all)->headb = tmp;
	(*all)->lheadb = tmp;
	(*all)->lheada = (*all)->heada;
	if ((*all)->headb && prntbl)
		write(1, "pa\n", 3);
	(*all)->bsize--;
	(*all)->size++;
}

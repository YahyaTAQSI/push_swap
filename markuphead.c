/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markuphead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:20:37 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/24 10:47:46 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lic_head(t_list *heada, t_list *lheada, int *lic, int key)
{
	t_list	*tmp;

	*lic = 0;
	tmp = heada;
	lheada = heada;
	while (heada)
	{
		tmp->key = 0;
		if (tmp->content >= heada->content)
		{
			(*lic)++;
			heada = tmp;
			if (key)
				heada->key = 1;
		}
		tmp = tmp->next;
		if (lheada == tmp)
			break ;
	}
	return (tmp);
}

void	ft_besthead(t_all *all, int *lic, int *plic)
{
	t_list	*tmp;
	t_list	*ptmp;

	*plic = 0;
	while (all->heada)
	{
		tmp = ft_lic_head(all->heada, all->lheada, lic, 0);
		if (*lic > *plic)
		{
			ptmp = tmp;
			*plic = *lic;
		}
		all->heada = all->heada->next;
		if (all->lheada == all->heada)
			break ;
	}
	ft_lic_head(ptmp, all->lheada, lic, 1);
}

void	ft_preparea(t_all *all)
{
	all->bsize = 0;
	while (all->size > all->plic)
	{
		if (fakeswap(all))
			continue ;
		else if (all->heada->key == 0)
			ft_pushb(&all, 1);
		else
			ft_rotatea(&all, 1);
	}
}

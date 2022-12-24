/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:51:24 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/21 11:53:02 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lp;

	lp = (t_list *)malloc(sizeof(t_list));
	if (!lp)
		return (NULL);
	lp->content = content;
	lp->key = 0;
	lp->next = lp;
	lp->prev = lp;
	return (lp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nextlst;
	t_list	*head;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	nextlst = *lst;
	while (nextlst->next != head)
		nextlst = nextlst->next;
	nextlst->next = new;
	new->next = head;
	new->prev = nextlst;
	head->prev = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = new;
	new->prev = new;
	if (*lst)
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
	}
	*lst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*nextlst;
	t_list	*currentlst;

	if (!lst)
		return ;
	nextlst = *lst;
	while (*lst)
	{
		currentlst = nextlst;
		nextlst = nextlst->next;
		free(currentlst);
		if (nextlst == *lst)
			break ;
	}
	*lst = NULL;
}

int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

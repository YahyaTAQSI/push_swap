/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:13:24 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/22 14:04:00 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_all	all;

	ft_parcing(ac, av, &all);
	ft_besthead(&all, &all.lic, &all.plic);
	ft_preparea(&all);
	thebestone(&all);
	rja3_lblastk(&all);
	return (0);
}

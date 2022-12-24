/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:41:38 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/22 12:03:47 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_overint(char **str)
{
	int		i;
	long	j;

	i = 0;
	while (str[i])
	{
		j = ft_atoi(str[i]);
		if (j > INT_MAX || j < INT_MIN)
			return (0);
		i++;
	}
	return (i);
}

int	ft_allint(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-')
			j++;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_dupint(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_parcing(int ac, char **av, t_all *all)
{
	int		i;
	char	**str;
	char	*join;

	if (ac == 1)
		exit(0);
	all->heada = NULL;
	all->headb = NULL;
	i = 0;
	join = ft_strjoin(ac - 1, av + 1, " ");
	str = ft_split(join, ' ');
	free(join);
	if (!ft_allint(str) || !ft_overint(str) || !ft_dupint(str))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (str[i])
		ft_lstadd_back(&all->heada, ft_lstnew(ft_atoi(str[i++])));
	freestr(str);
	all->size = i;
	all->lheada = all->heada;
}

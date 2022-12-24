/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:50:15 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/21 11:27:02 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	strl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*check(int size, char **strs, char *sep)
{
	char	*p;
	int		i;
	int		res;

	i = 0;
	res = 0;
	p = NULL;
	if (size == 0)
	{
		p = (char *)malloc(sizeof(char));
		if (!p)
			return (NULL);
		return (p);
	}
	while (i < size)
		res = res + strl(strs[i++]) + strl(sep);
	p = (char *)malloc((res - strl(sep) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	return (p);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		l;
	char	*p;

	p = NULL;
	i = 0;
	j = 0;
	l = 0;
	p = check(size, strs, sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			p[l++] = strs[i][j++];
		j = 0;
		if (i == size - 1)
			break ;
		while (sep[j])
			p[l++] = sep[j++];
		i++;
	}
	p[l] = '\0';
	return (p);
}

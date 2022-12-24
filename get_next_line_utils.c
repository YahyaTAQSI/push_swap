/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:44:27 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/22 12:07:36 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	while (s[i])
		i++;
	p = (char *) malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strmjoin(char *s1, char *s2)
{
	int		is1;
	int		is2;
	char	*p;

	is1 = ft_strlen(s1);
	is2 = ft_strlen(s2);
	p = (char *)malloc((is1 + is2 + 1) * sizeof(char));
	if (!p)
		return (NULL);
	is1 = 0;
	is2 = 0;
	while (s1 && s1[is1])
	{
		p[is1] = s1[is1];
		is1++;
	}
	while (s2[is2])
		p[is1++] = s2[is2++];
	p[is1] = '\0';
	free(s1);
	s1 = NULL;
	return (p);
}

ssize_t	checkline(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return (i);
}

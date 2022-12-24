/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:35:10 by ytaqsi            #+#    #+#             */
/*   Updated: 2022/12/22 15:33:42 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strmjoin(char *s1, char *s2);
ssize_t	checkline(char *s);

typedef struct s_list
{
	int				content;
	int				key;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_moves
{
	int			besta;
	int			bestb;
	int			moves;
	int			movea;
	int			moveb;
}				t_moves;

typedef struct s_all
{
	t_list	*heada;
	t_list	*lheada;
	t_list	*headb;
	t_list	*lheadb;
	int		bsize;
	int		lic;
	int		plic;
	int		size;
	int		dist;
	int		fcp;
	int		lcp;
}			t_all;

long	ft_atoi(const char *str);
char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_split(char const *s, char c);

void	ft_parcing(int ac, char **av, t_all *all);

t_list	*ft_lic_head(t_list *heada, t_list *lheada, int *lic, int key);
void	ft_besthead(t_all *all, int *lic, int *plic);
void	ft_preparea(t_all *all);

void	ft_pushb(t_all **all, int prntbl);
void	ft_pusha(t_all **all, int prntbl);

void	ft_sa(t_all **all, int prntbl);
void	ft_sb(t_all **all, int prntbl);
void	ft_ss(t_all **all, int printbl);
int		fakeswap(t_all *all);

void	ft_rotatea(t_all **all, int prntbl);
void	ft_rotateb(t_all **all, int prntbl);
void	ft_rotateab(t_all **all, int printbl);

void	ft_reversea(t_all **all, int prntbl);
void	ft_reverseb(t_all **all, int prntbl);
void	ft_reverseab(t_all **all, int printbl);

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

int		ft_abs(int n);
void	indexb(t_all *all);
void	thebestone(t_all *all);
void	rja3_lblastk(t_all *all);
void	checksign(t_moves *allmoves);
t_list	*whichone(t_all *all, int *cp);
void	checkwhichone(t_all *all, t_moves *allmoves);
void	checksign2(t_moves *allmoves);
void	rja3_lblastk2(t_all *all, int *cp2);
void	siri_l_a2(t_all *all, t_moves allmoves);
void	ft_lstclear(t_list **lst);
void	freestr(char **str);
char	*get_next_line(int fd);
int		ft_strcmp(char *s1, char *s2);

#endif

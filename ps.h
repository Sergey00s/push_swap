/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 00:09:00 by ialgac            #+#    #+#             */
/*   Updated: 2022/05/01 00:09:01 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_lst
{
	int	*sta;
	int	*stb;
	int	len;
	int	lenb;
	int	lena;
}				t_lst;

typedef struct s_prob
{
	int	neg;
	int	pos;
}				t_prob;

void	freesparg(char **sparg, char *args);
void	qut(int *alst);
void	pushlasta(t_lst *stack);
int		findlen(const char *arr);
int		aglen(const char **av, int ac);
void	sort3(t_lst *stack);
void	quits(char **sparg, int *rtn, char *args, int code);
int		checkrpt(int *arr, int len);
int		checkargs2(char *str, int *arr, int len);
int		checkargs(char *args, int len);
int		fcounts(int *arr, int len, int op);
int		ft_power(int i, int x);
void	iter(void *it);
void	startalgo(t_lst *stack);
void	startsecalgo(t_lst *stack, int len);
int		*index_args(int *arr, int len);
int		checkdubs(int *arr, int len);
int		pb(t_lst *stack);
int		pa(t_lst *stack);
int		ra(t_lst *stack);
int		rra(t_lst *stack);
int		sa(t_lst *stack);
int		sb(t_lst *stack);
#endif

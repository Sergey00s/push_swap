/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:52:30 by ialgac            #+#    #+#             */
/*   Updated: 2022/04/30 23:52:31 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	check_all_corr(int *a, int len)
{
	int	i;
	int	num;
	int	rtn;

	rtn = 1;
	i = 0;
	num = 1;
	while (i < len)
	{
		if (a[i] != num)
		{
			rtn = 0;
			break ;
		}
		i++;
		num++;
	}
	return (rtn);
}

void	run(int *alst, int len)
{
	t_lst	*stacks;
	int		*indx;

	indx = index_args(alst, len);
	if (check_all_corr(indx, len))
		qut(alst);
	stacks = malloc(sizeof(t_lst));
	stacks->sta = indx;
	stacks->stb = ft_calloc(sizeof(int), len);
	stacks->len = len;
	stacks->lena = len;
	stacks->lenb = 0;
	if (len == 3)
		sort3(stacks);
	else if (len > 5)
		startalgo(stacks);
	else
		startsecalgo(stacks, len);
	free(alst);
	free(indx);
	free(stacks->stb);
	free(stacks);
}

int	sizeofargs(const char **av, int len)
{
	int	i;
	int	rtn;
	int	k;

	i = 1;
	rtn = 0;
	while (i < len)
	{
		k = 0;
		while (av[i][k])
		{
			rtn++;
			k++;
		}
		i++;
	}
	return (rtn);
}

int	checkargs(char *args, int len)
{
	char	**sparg;
	int		*rtn;
	int		i;
	int		k;
	int		getlen;

	i = 0;
	k = 0;
	getlen = findlen(args);
	rtn = malloc(getlen * sizeof(int));
	sparg = ft_split((const char *)args, ' ');
	while (sparg[i])
	{
		rtn[k] = ft_atoi(sparg[i]);
		if (ft_atoi(sparg[i]) == -1 && ft_strlen(sparg[i]) > 2)
			quits(sparg, rtn, args, 1);
		k++;
		i++;
	}
	if (!checkargs2(args, rtn, len) || !checkrpt(rtn, getlen))
		quits(sparg, rtn, args, 2);
	freesparg(sparg, args);
	run(rtn, getlen);
	return (0);
}

int	main(int ac, char const **av)
{
	int		i;
	int		j;
	int		k;
	char	*args;

	i = 1;
	j = 0;
	args = malloc(sizeof(char) * (aglen(av, ac) + ac));
	while (i < ac)
	{
		k = 0;
		while (av[i][k])
		{
			args[j] = av[i][k];
			j++;
			k++;
		}
		args[j] = ' ';
		j++;
		i++;
	}	
	args[j] = 0;
	checkargs(args, ac - 1);
	return (0);
}

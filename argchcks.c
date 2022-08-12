/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argchcks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:32:35 by ialgac            #+#    #+#             */
/*   Updated: 2022/04/30 23:32:36 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	fcounts(int *arr, int len, int op)
{
	int	i;
	int	rtn;

	i = 0;
	rtn = 0;
	if (op == 1)
	{
		while (i < len)
			rtn = rtn + (arr[i++] > 0);
	}
	else if (op == 0)
	{
		while (i < len)
			rtn = rtn + (arr[i++] < 0);
	}
	return (rtn);
}

int	checkrpt(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (i != 0 && j >= 0 && j < len)
		{
			if (arr[j] == arr[i] && j != i)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	checkargs2(char *str, int *arr, int len)
{
	int	i;

	(void)arr;
	(void)len;
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (!ft_isdigit(str[i + 1]))
			{
				return (0);
			}
		}
		if (str[i] != '+' && str[i] != '-' && str[i] != ' ' && \
		!ft_isdigit(str[i]) && str[i] != 0 && \
		str[i] != '\t' && str[i] != 1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	quits(char **sparg, int *rtn, char *args, int code)
{
	int	i;

	i = 0;
	while (sparg[i])
	{
		free(sparg[i]);
		i++;
	}	
	free(sparg);
	free(rtn);
	free(args);
	ft_printf("Error %d\n", code);
	exit(0);
}

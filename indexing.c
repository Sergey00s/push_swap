/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 00:39:38 by ialgac            #+#    #+#             */
/*   Updated: 2022/05/01 00:39:39 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	selection_sort(int arr[], int n)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < (n - 1))
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap(&arr[min_idx], &arr[i]);
		i++;
	}
}

int	getindex(int *arr, int search)
{
	int	i;

	i = 0;
	while (1)
	{
		if (arr[i] == search)
			return (i);
		i++;
	}
	return (-1);
}

int	*index_args(int *arr, int len)
{
	int	*rtn;
	int	i;

	i = 0;
	rtn = ft_calloc(sizeof(int), len);
	while (i < len)
	{
		rtn[i] = arr[i];
		i++;
	}
	selection_sort(arr, len);
	i = 0;
	while (i < len)
	{
		rtn[i] = getindex(arr, rtn[i]) + 1;
		if (rtn[i] == -1)
		{
			ft_printf("error");
			exit(1);
		}
		i++;
	}
	return (rtn);
}

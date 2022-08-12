/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 06:15:49 by ialgac            #+#    #+#             */
/*   Updated: 2022/04/29 06:15:50 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sort3(t_lst *stack)
{
	if (stack->sta[0] == 1 && stack->sta[1] == 3 && stack->sta[2] == 2)
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->sta[0] == 2 && stack->sta[1] == 1 && stack->sta[2] == 3)
		sa(stack);
	else if (stack->sta[0] == 3 && stack->sta[1] == 2 && stack->sta[2] == 1)
	{
		ra(stack);
		sa(stack);
	}
	else if (stack->sta[0] == 4 && stack->sta[1] == 3 && stack->sta[2] == 1)
		rra(stack);
	else if (stack->sta[0] == 3 && stack->sta[1] == 1 && stack->sta[2] == 2)
		ra(stack);
	else if (stack->sta[0] == 2 && stack->sta[1] == 3 && stack->sta[2] == 1)
		rra(stack);
}

int	aglen(const char **av, int ac)
{
	int	i;
	int	rtn;

	i = 1;
	rtn = 0;
	while (i < ac)
	{
		rtn += ft_strlen(av[i]);
		i++;
	}
	return (rtn);
}

int	findlen(const char *arr)
{
	int	i;
	int	rtn;

	i = 0;
	rtn = 0;
	while (arr[i])
	{
		if (ft_isdigit(arr[i]))
		{
			while (ft_isdigit(arr[i]))
				i++;
			rtn++;
		}
		else
			i++;
	}
	return (rtn);
}

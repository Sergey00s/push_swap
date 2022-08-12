/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:27:48 by ialgac            #+#    #+#             */
/*   Updated: 2022/04/30 23:27:50 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_power(int x, int n)
{
	if (n <= 0)
		return (1);
	return (x * (ft_power(x, n - 1)));
}

int	check2base(int i, int n)
{
	return ((i / (ft_power(2, n))) % 2);
}

int	hesapla(int len, int result, int index)
{
	if (result > len)
		return (index);
	return (hesapla(len, result * 2, index + 1));
}

void	startalgo(t_lst *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < hesapla(stack->len, 1, 0))
	{
		j = stack->len;
		while (j--)
		{
			if (stack->lena && check2base(stack->sta[0], i) == 0)
				pb(stack);
			else
				ra(stack);
		}
		while (pa(stack))
			;
		i++;
	}
}

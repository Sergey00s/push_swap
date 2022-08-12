/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secalgo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 00:40:41 by ialgac            #+#    #+#             */
/*   Updated: 2022/05/01 00:40:42 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sort5(t_lst *stack);
void	sortbandfin(t_lst *stack);
void	sort4(t_lst *stack);

void	startsecalgo(t_lst *stack, int len)
{
	int	pbc;

	pbc = 0;
	while (pbc < 2 & len > 3)
	{
		if (stack->sta[0] == 1 || stack->sta[0] == 2)
		{
			pb(stack);
			pbc++;
		}
		else if (stack->sta[1] == 1 || stack->sta[1] == 2)
			sa(stack);
		else
			ra(stack);
	}
	if (len == 2)
		sa(stack);
	if (len == 5)
		sort5(stack);
	if (len == 4)
		sort4(stack);
	if (len > 2)
		sortbandfin(stack);
}

void	sort5(t_lst *stack)
{
	if (stack->sta[0] == 3 && stack->sta[1] == 5 && stack->sta[2] == 4)
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->sta[0] == 4 && stack->sta[1] == 3 && stack->sta[2] == 5)
		sa(stack);
	else if (stack->sta[0] == 5 && stack->sta[1] == 4 && stack->sta[2] == 3)
	{
		ra(stack);
		sa(stack);
	}
	else if (stack->sta[0] == 4 && stack->sta[1] == 5 && stack->sta[2] == 3)
		rra(stack);
	else if (stack->sta[0] == 5 && stack->sta[1] == 3 && stack->sta[2] == 4)
		ra(stack);
}

void	sortbandfin(t_lst *stack)
{
	if (stack->stb[0] == 1 && stack->stb[1] == 2)
		sb(stack);
	pa(stack);
	pa(stack);
}

void	sort4(t_lst *stack)
{
	if (stack->sta[0] == 4 && stack->sta[1] == 3)
		sa(stack);
}

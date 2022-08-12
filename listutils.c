/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:41:10 by ialgac            #+#    #+#             */
/*   Updated: 2022/04/30 23:41:12 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	pb(t_lst *stack)
{
	if (stack->lenb >= stack->len)
		return (0);
	ft_memmove(&stack->stb[1], stack->stb, sizeof(int) * stack->lenb);
	stack->stb[0] = stack->sta[0];
	ft_memmove(stack->sta, &stack->sta[1], sizeof(int) * stack->lena);
	stack->lenb++;
	stack->lena--;
	ft_printf("pb\n");
	return (1);
}

int	pa(t_lst *stack)
{
	if (stack->lena >= stack->len)
		return (0);
	ft_memmove(&stack->sta[1], stack->sta, sizeof(int) * stack->lena);
	stack->sta[0] = stack->stb[0];
	ft_memmove(stack->stb, &stack->stb[1], sizeof(int) * stack->lenb);
	stack->lena++;
	stack->lenb--;
	ft_printf("pa\n");
	return (1);
}

int	ra(t_lst *stack)
{
	int	temp;

	if (!(stack->lena >= 2))
		return (0);
	temp = stack->sta[0];
	ft_memmove(stack->sta, &stack->sta[1], sizeof(int) * (stack->lena - 1));
	stack->sta[stack->lena - 1] = temp;
	ft_printf("ra\n");
	return (1);
}

int	sa(t_lst *stack)
{
	int	temp;

	if (!(stack->lena >= 2))
		return (0);
	temp = stack->sta[0];
	stack->sta[0] = stack->sta[1];
	stack->sta[1] = temp;
	ft_printf("sa\n");
	return (1);
}

int	sb(t_lst *stack)
{
	int	temp;

	if (!(stack->lenb >= 2))
		return (0);
	temp = stack->stb[0];
	stack->stb[0] = stack->stb[1];
	stack->stb[1] = temp;
	ft_printf("sb\n");
	return (1);
}

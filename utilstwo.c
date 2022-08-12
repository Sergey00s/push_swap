/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 00:05:10 by ialgac            #+#    #+#             */
/*   Updated: 2022/05/01 00:05:11 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	qut(int *alst)
{
	free(alst);
	exit(0);
}

int	rra(t_lst *stack)
{
	int	temp;

	if (!(stack->lena >= 2))
		return (0);
	temp = stack->sta[stack->lena - 1];
	ft_memmove(&stack->sta[1], stack->sta, sizeof(int) * (stack->lena - 1));
	stack->sta[0] = temp;
	ft_printf("rra\n");
	return (1);
}

void	freesparg(char **sparg, char *args)
{
	int	i;

	i = 0;
	while (sparg[i])
		free(sparg[i++]);
	free(sparg[i]);
	free(sparg);
	free(args);
}

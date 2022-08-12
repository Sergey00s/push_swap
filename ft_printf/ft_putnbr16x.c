/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr16x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:37:47 by ialgac            #+#    #+#             */
/*   Updated: 2022/02/02 18:37:49 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputnbr16x(unsigned int nbr, char *a)
{
	int	rtn;

	rtn = 0;
	if (nbr >= 16)
		rtn += ft_fputnbr16x(nbr / 16, a);
	return (rtn + ft_fputchar_fd(a[nbr % 16], 1));
}

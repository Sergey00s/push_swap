/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:47:03 by ialgac            #+#    #+#             */
/*   Updated: 2022/01/30 18:47:06 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputnbr16f(unsigned long int nbr, char *a)
{
	int	rtn;

	rtn = 0;
	if (nbr >= 16)
		rtn += ft_fputnbr16f(nbr / 16, a);
	return (rtn + ft_fputchar_fd(a[nbr % 16], 1));
}

int	ft_fputnbr16(unsigned long nbr, char *a)
{
	return (ft_fputstr_fd("0x", 1) + ft_fputnbr16f(nbr, a));
}

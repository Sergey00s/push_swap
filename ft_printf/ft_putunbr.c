/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:40:31 by ialgac            #+#    #+#             */
/*   Updated: 2022/02/02 18:40:32 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputunbr_fd(unsigned int n, int fd)
{
	int	writed;

	writed = 0;
	if (n > 9)
		writed += ft_fputnbr_fd(n / 10, fd);
	return (writed + ft_fputchar_fd(n % 10 + '0', fd));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:31:56 by ialgac            #+#    #+#             */
/*   Updated: 2022/02/02 18:31:57 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	inflags(char c)
{
	char	*flags;
	int		i;

	flags = "csdipuxX%";
	i = 0;
	while (flags[i])
	{
		if (flags[i++] == c)
			return (1);
	}
	return (0);
}

static int	putparam(char c, va_list args)
{
	if (c == 'c')
		return (ft_fputchar_fd((char)(va_arg(args, int)), 1));
	else if (c == 's')
		return (ft_fputstr_fd(va_arg(args, char *), 1));
	else if (c == 'd')
		return (ft_fputnbr_fd(va_arg(args, int), 1));
	else if (c == 'i')
		return (ft_fputnbr_fd(va_arg(args, int), 1));
	else if (c == 'p')
		return (ft_fputnbr16(va_arg(args, unsigned long), HEX));
	else if (c == 'u')
		return (ft_fputunbr_fd(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (ft_fputnbr16x(va_arg(args, int), HEX));
	else if (c == 'X')
		return (ft_fputnbr16x(va_arg(args, int), C_HEX));
	else if (c == '%')
		return (ft_fputchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{	
	va_list	args;
	int		rtn;

	rtn = 0;
	va_start(args, s);
	while (s && *s)
	{
		if (*s == '%' && inflags(*(s + 1)))
			rtn += putparam(*(s++ + 1), args);
		else
			rtn += ft_fputchar_fd(*s, 1);
		s++;
	}
	va_end(args);
	return (rtn);
}

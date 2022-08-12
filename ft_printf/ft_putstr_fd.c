/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:50:22 by ialgac            #+#    #+#             */
/*   Updated: 2022/01/30 17:34:16 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return (ft_fputstr_fd("(null)", 1));
	while (s[i])
		ft_fputchar_fd(s[i++], fd);
	return (i);
}

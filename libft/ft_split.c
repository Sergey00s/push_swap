/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:50:03 by ialgac            #+#    #+#             */
/*   Updated: 2022/01/13 10:41:36 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	w_l(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (s[r] != '\0' && s[r] != c)
		r++;
	return (r);
}

static size_t	w_c(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			r++;
		s++;
	}
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	size_t	i;
	size_t	l;
	size_t	w_i;

	if (!s)
		return (NULL);
	l = w_c(s, c);
	r = (char **)malloc(sizeof(char *) * l + 1);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		while (*s == c && *s != '\0')
			s++;
		r[i] = (char *)malloc(sizeof(char) * w_l(s, c) + 1);
		w_i = 0;
		while (*s != c && *s != '\0')
			r[i][w_i++] = *s++;
		r[i][w_i] = '\0';
		i++;
	}
	r[i] = NULL;
	return (r);
}

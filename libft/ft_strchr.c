/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:29:05 by ygomes-d          #+#    #+#             */
/*   Updated: 2021/12/10 22:39:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	compare;

	str = (char *)s;
	compare = (unsigned char)c;
	while (*str)
	{
		if (*str == compare)
			return (str);
		str++;
	}
	if (!compare && !*str)
		return (str);
	return (NULL);
}
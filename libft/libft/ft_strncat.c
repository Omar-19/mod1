/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:27:03 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/10 21:49:58 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned char	*p2;
	char			*str;
	int				f;

	f = 0;
	str = s1;
	p2 = (unsigned char *)s2;
	while (*str != '\0')
		str++;
	while (n > 0 && *p2 != '\0')
	{
		if (*p2 == '\0')
			f = 1;
		if (f == 0)
			*str = *p2;
		else
			*str = '\0';
		str++;
		p2++;
		n--;
	}
	*str = '\0';
	return (s1);
}

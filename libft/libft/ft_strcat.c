/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:53:04 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/05 17:26:52 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char			*str;
	unsigned char	*p2;

	p2 = (unsigned char *)s2;
	str = s1;
	while (*str != '\0')
		str++;
	while (*p2 != '\0')
	{
		*str = *p2;
		str++;
		p2++;
	}
	*str = '\0';
	return (s1);
}

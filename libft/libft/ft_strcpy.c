/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:19:25 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/05 16:52:48 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned char	*str;
	char			*prt;

	str = (unsigned char *)src;
	prt = dst;
	while (*str != '\0')
	{
		*prt = *str;
		prt++;
		str++;
	}
	*prt = '\0';
	return (dst);
}

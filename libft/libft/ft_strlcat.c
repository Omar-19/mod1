/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:38:47 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/07 17:51:45 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;
	unsigned int length_dest;

	if (size == 0)
		return (size + ft_strlen(src));
	length_dest = ft_strlen(dst);
	i = length_dest;
	j = 0;
	while (size - 1 > i && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (ft_strlen(src) + length_dest > size + ft_strlen(src))
		return ((size_t)(size + ft_strlen(src)));
	else
		return ((size_t)(length_dest + ft_strlen(src)));
}

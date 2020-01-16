/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:16:19 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/07 15:53:39 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (ptr1 == ptr2 && ptr1 == NULL)
		return (NULL);
	if (ptr1 > ptr2)
		while (len > 0)
		{
			len--;
			ptr1[len] = ptr2[len];
		}
	else
		while (len > 0)
		{
			*ptr1++ = *ptr2++;
			len--;
		}
	return (dst);
}

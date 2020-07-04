/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:20:27 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/11 17:13:31 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (!(size + 1 > size))
		return (NULL);
	if (!(ptr = (void *)malloc(size)))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dopfunction2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:08:03 by btheia            #+#    #+#             */
/*   Updated: 2019/11/02 19:00:16 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		search_non(uint64_t *tmp, int ndb)
{
	int i;

	i = 0;
	while (i < ndb)
	{
		if (tmp[i])
			return (i);
		++i;
	}
	return (0);
}

void	init_help_del1(__uint128_t *a, int *o, int deg)
{
	a[0] = (__uint128_t)2 << (deg - 1);
	a[1] = 0;
	*o = -1;
}

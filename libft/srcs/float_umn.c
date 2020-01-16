/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_umn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:08:48 by btheia            #+#    #+#             */
/*   Updated: 2019/11/02 19:21:49 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		break_umn(uint64_t *tmp, int pos, int *min, __uint128_t s)
{
	tmp[pos] = (uint64_t)s;
	--(*min);
}

int			help_umn(uint64_t *tmp, int pos, __uint128_t f, __uint128_t *s)
{
	tmp[pos] = (uint64_t)(f % RAZR);
	*s = (uint64_t)(f / RAZR);
	return (1);
}

void		init_help(__uint128_t *s, __uint128_t *c, int *i, int deg)
{
	if (deg > 0)
		*c = ((__uint128_t)2 << (deg - 1));
	else if (deg < 0)
		*c = (__uint128_t)10;
	else
		*c = (__uint128_t)1;
	*s = 0;
	*i = -1;
}

void		umn1(uint64_t *tmp, int deg, int *min, int ndb)
{
	int			i;
	__uint128_t	a[3];

	init_help(&a[1], &a[2], &i, deg);
	while (*min <= ndb - (++i))
	{
		if (a[1])
		{
			if (umpres(a, tmp, ndb - i))
			{
				if ((help_umn(tmp, ndb - i, a[0], &a[1])) && *min == ndb - i)
					return (break_umn(tmp, ndb - i - 1, min, a[1]));
				++i;
			}
			else if (*min == ndb - i)
				return (break_umn(tmp, ndb - i, min, a[0]));
		}
		if (umpres(a, tmp, ndb - i))
		{
			if ((help_umn(tmp, ndb - i, a[0], &a[1])) && *min == ndb - i)
				return (break_umn(tmp, ndb - i - 1, min, a[1]));
		}
		else
			tmp[ndb - i] = a[0];
	}
}

void		umn(uint64_t *tmp, int deg, int *min, int ndb)
{
	int i;

	i = -1;
	if (deg <= 62)
	{
		umn1(tmp, deg, min, ndb);
		return ;
	}
	else
	{
		if (deg % 62)
			umn1(tmp, deg % 62, min, ndb);
		while (++i < deg / 62)
			umn1(tmp, 62, min, ndb);
	}
}

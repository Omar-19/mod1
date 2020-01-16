/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:41:41 by btheia            #+#    #+#             */
/*   Updated: 2019/10/20 17:23:50 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		sum_mhelp3(uint64_t *res, int pos, int min, __uint128_t s)
{
	res[pos - 1] = s;
	return (--min);
}

void	sum_mhelp4(uint64_t *res, int pos, __uint128_t *s, __uint128_t f)
{
	res[pos] = f;
	*s = 0;
}

int		sum_mhelp5(__uint128_t *a, uint64_t *res, int pos, int min)
{
	sum_mhelp2(&a[1], a[0], pos, res);
	if (min == pos)
	{
		sum_mhelp3(res, pos, min, a[1]);
		return (1);
	}
	return (0);
}

int		sum_mhelp6(__uint128_t *a, uint64_t *res, int pos)
{
	if (a[0] > 10000000000000000000U - 1)
		return (1);
	sum_mhelp4(res, pos, &a[1], a[0]);
	return (0);
}

int		sum_m(uint64_t *res, uint64_t *tmp, int min, int ndb)
{
	__uint128_t a[2];
	int			i;

	sum_mhelp(&a[1], &i);
	while (min <= ndb - (++i))
	{
		if (a[1] && (a[0] = (__uint128_t)res[ndb - i] + a[1]))
		{
			if (sum_mhelp6(a, res, ndb - i))
				if (sum_mhelp5(a, res, ndb - i, min))
					return (--min);
		}
		a[0] = (__uint128_t)res[ndb - i] + (__uint128_t)tmp[ndb - i] + a[1];
		if (a[0] > 10000000000000000000U - 1)
		{
			if (sum_mhelp5(a, res, ndb - i, min))
				return (--min);
		}
		else
			res[ndb - i] = a[0];
	}
	return (min);
}

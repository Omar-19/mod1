/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:51:43 by btheia            #+#    #+#             */
/*   Updated: 2019/10/20 18:17:02 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ret_byties_float(t_double d, int *a, int type, char *l)
{
	int k;
	int j;

	k = 0;
	j = type - 1;
	while (j >= 0)
	{
		l[k] = ((*(__uint128_t *)(&d.numld) >> j) & 1) + '0';
		++k;
		--j;
	}
	l[type + 1] = 0;
	(l[0] == '1') ? *a = 1 : 0;
}

char	*cr_dc(char *s, size_t m1, int len, int i)
{
	uint64_t	res[m1];
	uint64_t	tmp[m1];
	int			res_n;
	int			tmp_n;

	res_n = m1 - 1;
	tmp_n = m1 - 1;
	init_massiv(res, tmp, m1);
	while (len >= 0)
	{
		if (s[len] == '1')
		{
			umn(tmp, i - len, &tmp_n, m1 - 1);
			res_n = sum_m(res, tmp, min_i(&res_n, &tmp_n), m1 - 1);
			toone(tmp, m1);
			tmp[m1 - 1] = 1;
			tmp_n = m1 - 1;
		}
		--len;
	}
	return (cr_sdc(res, res_n, m1));
}

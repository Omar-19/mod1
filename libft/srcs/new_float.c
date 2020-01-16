/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:47:08 by btheia            #+#    #+#             */
/*   Updated: 2019/11/11 18:31:07 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_dec_part(char *m, int p)
{
	int		max_deg;
	size_t	m1;
	int		n1;

	max_deg = p;
	n1 = max_deg / 10 + 1;
	m1 = (n1 * 3) / 19 + 1;
	return (cr_dc_new(m, m1 + 1, max_deg, 0));
}

char	*res_last_new(char *dec, char *point, int prs, int sign)
{
	char	rs[ft_strlen(dec) + (size_t)3 + ft_strlen(point) + 1 + prs];
	char	*jk;
	int		ck;
	char	*k;

	ft_memset(rs, 0, ft_strlen(dec) + (size_t)3 + ft_strlen(point) + prs);
	jk = rs + 2;
	ft_strcat(rs + 2, dec);
	ft_strcat(rs + 2, ".");
	ft_strcat(rs + 2, point);
	if ((int)ft_strlen(point) < prs)
	{
		k = ft_strnewc(prs - ft_strlen(point), '0');
		ft_strcat(rs + 2, k);
		free(k);
	}
	free(dec);
	free(point);
	if (prs == 0 && !(check_c(ft_strchr(rs + 2, '.') + 2)))
		return (okrug_zero(&jk, sign));
	ck = okrug1(&jk, prs);
	(sign == 1) ? set_min(&jk, '-') : 0;
	if (ck && sign)
		return (ft_strdup(rs));
	return (ft_strdup(jk));
}

char	*get_float_all(char *m, int p, int prs, int sign)
{
	char *dec;
	char *point;

	if (p < 0)
	{
		dec = ft_strdup("0");
		point = get_point_part(m, p, prs);
	}
	else if (p >= 0 && (size_t)p < ft_strlen(m) - 1)
	{
		dec = get_dec_part(m, p);
		point = get_point_part2(m + p + 1, prs);
	}
	else
	{
		dec = get_dec_part(m, p);
		point = ft_strnewc(prs, '0');
	}
	return (res_last_new(dec, point, prs, sign));
}

char	*new_float_d(t_double d, int prs)
{
	int		sign;
	char	mantis[54];
	int		p;

	mantis[0] = '1';
	get_mm(&d.numd, mantis);
	sign = (*(__uint128_t *)(&d.numld) >> 63 & 1);
	p = RETD(d.numd);
	return (get_float_all(mantis, p, prs, sign));
}

char	*new_float_ld(t_double d, int prs)
{
	int		sign;
	char	mantis[65];
	int		p;

	get_mantis_d(d, mantis, 0);
	sign = (*(__uint128_t *)(&d.numld) >> 79 & 1);
	p = RETLD(d.numld);
	return (get_float_all(mantis, p, prs, sign));
}

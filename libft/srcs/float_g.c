/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:34:45 by btheia            #+#    #+#             */
/*   Updated: 2019/11/03 13:34:12 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*res_last3_g(char *point, int prs, int sign)
{
	char	*jk;
	char	rs[ft_strlen(point) + 2];
	int		i;

	ft_memset(rs, 0, ft_strlen(point) + 2);
	jk = rs + 1;
	ft_strncat(rs + 1, "0", 1);
	ft_strcat(rs + 1, ".");
	ft_strcat(rs + 1, point);
	okrug1(&jk, prs);
	if (sign == 1)
		set_min(&jk, '-');
	i = ft_strlen(jk) - 1;
	while (jk[i] == '0')
		i--;
	jk[i + 1] = '\0';
	return (ft_strdup(jk));
}

char	*res_last_g(char *resdec, char *pt, int prs, int sign)
{
	char	*jk;
	int		ck;
	char	rs[ft_strlen(resdec) + 5 + ft_strlen(pt) + raz(ft_strlen(resdec))];

	if (ft_strcmp(resdec, "0") == 0)
		return (res_last3_g(pt, 6, sign));
	if (ft_strlen(resdec) <= 6)
		return (res_last4_g(resdec, pt, sign));
	ft_memset(rs, 0, ft_strlen(resdec) + 5 + ft_strlen(pt)
		+ raz(ft_strlen(resdec)));
	jk = rs + 1;
	ft_strncat(rs + 1, resdec, 1);
	ck = 0;
	if (num_zer(resdec + 1) <= 5)
	{
		ft_strcat(rs + 1, ".");
		ft_strncat(rs + 1, resdec + 1, 5);
		ck = okrug1(&jk, prs);
	}
	(sign == 1) ? set_min(&jk, '-') : 0;
	ft_strcat(jk, "e+");
	ft_strcat(jk, ft_uint64toa2(ft_strlen(resdec) - 1, 0));
	if (ck && sign)
		return (ft_strdup(rs));
	return (ft_strdup(jk));
}

char	*get_float_all_g(char *m, int p, int prs, int sign)
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
	return (res_last_g(dec, point, prs, sign));
}

char	*float_dg(t_double d, int prs, int *sign)
{
	char	mantis[54];
	int		p;

	mantis[0] = '1';
	get_mm(&d.numd, mantis);
	*sign = (*(__uint128_t *)(&d.numld) >> 63 & 1);
	p = RETD(d.numd);
	return (get_float_all_g(mantis, p, prs, *sign));
}

char	*float_ldg(t_double d, int prs, int *sign)
{
	char	mantis[65];
	int		p;

	get_mantis_d(d, mantis, 0);
	*sign = (*(__uint128_t *)(&d.numld) >> 79 & 1);
	p = RETLD(d.numld);
	return (get_float_all_g(mantis, p, prs, *sign));
}

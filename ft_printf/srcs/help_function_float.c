/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:49:39 by btheia            #+#    #+#             */
/*   Updated: 2019/11/02 20:50:06 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_point_part(char *m, int p, int t)
{
	int		max_deg[2];
	int		n1;
	size_t	m1;

	t++;
	max_deg[0] = (-1 * p) + ft_strlen(m) - 1;
	max_deg[1] = ft_strlen(m);
	n1 = max_deg[0] / 4 + 1;
	(t < 17) ? t = 18 : t++;
	m1 = (n1 * 3) / 19 + 1;
	return (drob1_new(m, m1 + 1 + max_deg[0], max_deg));
}

char	*drob1_new(char *s, size_t m1, int *max_d)
{
	uint64_t	res[m1];
	uint64_t	tmp[m1];
	int			i;
	int			res_n;
	int			tmp_n;

	res_n = m1 - 1;
	tmp_n = m1 - 1;
	i = -1;
	init_massiv(res, tmp, m1);
	while (s[++i])
	{
		if (s[i] == '1')
		{
			umn5(tmp, max_d[0] - max_d[1] + i + 1, &tmp_n, m1 - 1);
			res_n = sum_m(res, tmp, min_i(&res_n, &tmp_n), m1 - 1);
			toone(tmp, m1);
			tmp[m1 - 1] = 1;
			tmp_n = m1 - 1;
		}
		res_n = search_non(res, m1);
		umn1(res, -1, &res_n, m1 - 1);
		res_n = search_non(res, m1);
	}
	return (cr_sdc_drob(res, res_n, m1, max_d[0]));
}

char	*cr_dc_new(char *s, size_t m1, int max_deg, int i)
{
	uint64_t	res[m1];
	uint64_t	tmp[m1];
	int			res_n;
	int			tmp_n;

	res_n = m1 - 1;
	tmp_n = m1 - 1;
	init_massiv(res, tmp, m1);
	while (s[i] && i < max_deg + 1)
	{
		if (s[i] == '1')
		{
			umn(tmp, max_deg - i, &tmp_n, m1 - 1);
			res_n = sum_m(res, tmp, min_i(&res_n, &tmp_n), m1 - 1);
			toone(tmp, m1);
			tmp[m1 - 1] = 1;
			tmp_n = m1 - 1;
		}
		++i;
	}
	return (cr_sdc(res, res_n, m1));
}

char	*res_last4_g(char *des, char *point, int sign)
{
	char	*jk;
	char	rs[8 + ft_strlen(point)];
	int		i;

	ft_memset(rs, 0, 8);
	jk = rs + 1;
	ft_strcat(rs + 1, des);
	ft_strcat(rs + 1, ".");
	ft_strcat(rs + 1, point);
	okrug1(&jk, 6 - ft_strlen(des));
	if (sign == 1)
		set_min(&jk, '-');
	i = ft_strlen(jk) - 1;
	while (jk[i] == '0')
		i--;
	jk[i + 1] = '\0';
	return (ft_strdup(jk));
}

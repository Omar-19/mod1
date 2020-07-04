/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dopfunction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:01:44 by btheia            #+#    #+#             */
/*   Updated: 2019/11/07 20:51:55 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_min(char **d, char c)
{
	char *res;

	res = *d - 1;
	res[0] = c;
	*d = res;
}

char	*drob(char *s, int t)
{
	int		max_deg;
	int		n1;
	size_t	m1;

	max_deg = ft_strlen(s);
	n1 = max_deg / 4 + 1;
	if (max_deg == 0 || !ft_strrchr(s, '1'))
		return (ft_strnewc(t, '0'));
	(t < 17) ? t = 18 : t++;
	m1 = (n1 * 3) / 19 + 1;
	return (drob1(s, m1 + 1 + max_deg, max_deg));
}

int		col_zero(uint64_t *a, int min, size_t m1, int max_deg)
{
	int b;

	b = raz(a[min]);
	return (max_deg - b - 19 * (m1 - min - 1));
}

char	*cr_sdc_drob(uint64_t *a, int min, size_t m1, int max_deg)
{
	char	*res;
	int		len;
	int		l;
	char	*rk;

	l = col_zero(a, min, m1, max_deg) + 1;
	len = 19 * (m1 - min) + l;
	if (!(res = ft_strnew(len)))
		return (NULL);
	ft_memset(res, '0', len);
	res[l] = '\0';
	rk = ft_uint64toa(a[min++], 0);
	ft_strcat(res, rk);
	free(rk);
	while ((size_t)min < m1)
	{
		rk = ft_uint64toa(a[min], 1);
		ft_strcat(res, rk);
		free(rk);
		++min;
	}
	return (res);
}

char	*drob1(char *s, size_t m1, int max_d)
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
			umn5(tmp, i + 1, &tmp_n, m1 - 1);
			res_n = sum_m(res, tmp, min_i(&res_n, &tmp_n), m1 - 1);
			toone(tmp, m1);
			tmp[m1 - 1] = 1;
			tmp_n = m1 - 1;
		}
		res_n = search_non(res, m1);
		umn1(res, -1, &res_n, m1 - 1);
		res_n = search_non(res, m1);
	}
	return (cr_sdc_drob(res, res_n, m1, max_d));
}

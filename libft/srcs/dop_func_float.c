/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:21:52 by btheia            #+#    #+#             */
/*   Updated: 2019/11/02 15:22:34 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*main_c(char *s)
{
	int		max_deg;
	size_t	m1;
	int		n1;

	if (ft_strcmp(s, "0") == 0)
		return (ft_strdup(s));
	max_deg = ft_strlen(s) - 1;
	n1 = max_deg / 10 + 1;
	m1 = (n1 * 3) / 19 + 1;
	return (cr_dc(s, m1 + 1, max_deg, max_deg));
}

void	toone(uint64_t *tmp, int m1)
{
	int i;

	i = 0;
	while (i < m1)
	{
		tmp[i] = 0;
		++i;
	}
}

char	*cr_sdc(uint64_t *a, int min, size_t m1)
{
	char *res;
	char *r;

	if (!(res = ft_strnew(19 * (m1 - min))))
		return (NULL);
	r = ft_uint64toa(a[min++], 0);
	ft_strcat(res, r);
	free(r);
	while ((size_t)min < m1)
	{
		r = ft_uint64toa(a[min], 1);
		ft_strcat(res, r);
		free(r);
		++min;
	}
	return (res);
}

void	init_massiv(uint64_t *res, uint64_t *tmp, size_t m1)
{
	toone(res, m1);
	toone(tmp, m1);
	tmp[m1 - 1] = 1;
}

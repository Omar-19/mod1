/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:40:19 by btheia            #+#    #+#             */
/*   Updated: 2019/11/02 20:48:49 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	octa_intc(char *s)
{
	char c;

	c = '0';
	(!(*(int*)s ^ *(int*)"000")) ? c = '0' : 0;
	(!(*(int*)s ^ *(int*)"001")) ? c = '1' : 0;
	(!(*(int*)s ^ *(int*)"010")) ? c = '2' : 0;
	(!(*(int*)s ^ *(int*)"011")) ? c = '3' : 0;
	(!(*(int*)s ^ *(int*)"100")) ? c = '4' : 0;
	(!(*(int*)s ^ *(int*)"101")) ? c = '5' : 0;
	(!(*(int*)s ^ *(int*)"110")) ? c = '6' : 0;
	(!(*(int*)s ^ *(int*)"111")) ? c = '7' : 0;
	return (c);
}

void	help_octa1(char *buf)
{
	buf[0] = '0';
	buf[1] = '0';
	buf[2] = '0';
}

void	get_mantis_d(t_double d, char *s, int type)
{
	int		i;
	int		j;
	char	*n;

	n = NULL;
	j = 63 - 12 * type;
	i = type;
	while (j >= 0)
	{
		s[i] = ((*(__uint128_t *)(&d.numld) >> j) & 1) + '0';
		(s[i] == '0' && !n) ? (n = &s[i]) : 0;
		(s[i] == '1') ? (n = NULL) : 0;
		++i;
		--j;
	}
	s[i] = 0;
	(n != NULL) ? *n = 0 : 0;
}

void	get_mm(void *a, char *s)
{
	int		i;
	int		j;
	char	*n;

	n = NULL;
	j = 51;
	i = 1;
	while (j >= 0)
	{
		s[i] = ((*(uint64_t*)(a) >> j) & 1) + '0';
		(s[i] == '0' && !n) ? (n = &s[i]) : 0;
		(s[i] == '1') ? (n = NULL) : 0;
		++i;
		--j;
	}
	s[i] = 0;
	(n != NULL) ? *n = 0 : 0;
}

char	*get_point_part2(char *m, int t)
{
	int		max_deg;
	int		n1;
	size_t	m1;

	t++;
	max_deg = ft_strlen(m);
	n1 = max_deg / 4 + 1;
	(t < 17) ? t = 18 : t++;
	m1 = (n1 * 3) / 19 + 1;
	return (drob1(m, m1 + 1 + max_deg, max_deg));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:54:50 by btheia            #+#    #+#             */
/*   Updated: 2019/11/11 18:48:16 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*bit_out(void *a)
{
	char	res[65];
	int		j;
	int		i;

	i = 63;
	j = -1;
	ft_memset(res, '0', 64);
	while (i >= 0)
	{
		res[++j] = ((*(__uint128_t *)a >> i) & 1) + '0';
		i--;
	}
	res[++j] = 0;
	j = 0;
	while (res[j] == '0' && j < 63)
		j++;
	return (ft_strdup(res + j));
}

int		check_c(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '0')
			return (1);
		++i;
	}
	return (0);
}

void	pres1(int *a, char *s, char *p, int t)
{
	a[1] = 0;
	a[0] = p - s + t + 1;
}

void	pres2(int *a, char **s, char **d)
{
	*a = 1;
	*d = *s - 1;
}

int		okrug1(char **d, int t)
{
	char	*point;
	char	*s;
	int		i[2];

	s = *d;
	point = ft_strchr(s, '.');
	pres1(i, s, point, t);
	if (check_c(point + 1) == 1 && s[i[0]] >= '5')
	{
		while (--i[0] >= 0)
		{
			if (s[i[0]] != '9' && s[i[0]] != '.')
			{
				s[i[0]] += 1;
				break ;
			}
			(s[i[0]] != '.') ? s[i[0]] = '0' : 0;
		}
		if (i[0] == -1 && (*(s - 1) = '1'))
			pres2(&i[1], &s, d);
	}
	ft_memset(point + t + 1, '\0', ft_strlen(point));
	(t == 0) ? (ft_memset(point, '\0', ft_strlen(point))) : 0;
	return (i[1]);
}

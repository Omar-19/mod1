/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_funchelp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:14:56 by btheia            #+#    #+#             */
/*   Updated: 2019/11/11 19:08:15 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sum_mhelp(__uint128_t *s, int *i)
{
	*s = 0;
	*i = -1;
}

void	sum_mhelp2(__uint128_t *s, __uint128_t f, int pos, uint64_t *res)
{
	res[pos] = f % 10000000000000000000U;
	*s = f / 10000000000000000000U;
}

char	*get_val(char *s)
{
	char *res;
	char *l;

	l = ft_strrchr(s, '1');
	res = ft_strnew(l - s + 1);
	ft_memmove(res, s, l - s + 1);
	return (res);
}

char	*ft_strnewc(size_t n, char c)
{
	char *res;

	res = ft_strnew(n);
	ft_memset(res, c, n);
	return (res);
}

char	*okrug_zero(char **r, int sign)
{
	char	*point;
	char	*s;
	int		i[2];

	s = *r;
	point = ft_strchr(s, '.');
	help_okrug_zero(i, s, 0, point);
	if (s[i[0]-- - 1] >= '5')
	{
		while (--i[0] >= 0)
		{
			if (s[i[0]] != '9' && s[i[0]] != '.')
			{
				help_okrug_zero(i, s, 1, point);
				break ;
			}
			i[1] = 0;
			(s[i[0]] != '.') ? s[i[0]] = '0' : ++i[1];
		}
		if (i[0] == -1 && (*(s - 1) = '1'))
			pres2(&i[0], &s, r);
	}
	ft_memset(point, '\0', ft_strlen(point));
	(sign == 1) ? set_min(r, '-') : 0;
	return (ft_strdup(*r));
}

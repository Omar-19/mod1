/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:35:29 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/02 20:45:58 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*main_p(char **s, int pos)
{
	char *res;

	if (pos >= 0)
	{
		res = ft_strnewc(pos + ft_strlen(*s) + 1, '0');
		ft_memmove(res, *s, ft_strlen(*s));
		res[pos + 1] = ',';
		if (pos < 0 || ((unsigned long)pos < ft_strlen(*s) - 1))
			ft_memmove(res + pos + 2, *s + pos + 1, ft_strlen(*s + pos));
		free(*s);
		*s = res;
		return (&res[pos + 1]);
	}
	else
	{
		pos = -pos + 1;
		res = ft_strnewc(ft_strlen(*s) + pos, '0');
		ft_memmove(res + pos, *s, ft_strlen(*s));
		res[1] = ',';
		free(*s);
		*s = res;
		return (&res[1]);
	}
}

char	*set_p(char *s, int pos)
{
	char	*l;
	int		i;

	l = ft_strnew(ft_strlen(s) + pos + 1);
	i = -1;
	while (++i < pos)
		l[i] = s[i];
	l[pos] = ',';
	ft_memmove(l + pos + 1, s + i, ft_strlen(s + i));
	return (l);
}

int		min_i(int *a, int *b)
{
	if (*a > *b)
		return (*b);
	return (*a);
}

char	*float_c(va_list a, int prs, char *type)
{
	t_double		d;
	int				sign;

	if (!ft_strncmp("Lf", type, 2))
	{
		d.numld = va_arg(a, long double);
		return (float_ld(d, prs, &sign));
	}
	else if (!ft_strncmp("lf", type, 2))
	{
		d.numd = va_arg(a, double);
		return (float_d(d, prs, &sign));
	}
	else
	{
		d.numf = (float)va_arg(a, double);
		return (float_f(d, prs, &sign));
	}
}

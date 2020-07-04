/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_help_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:30:27 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/07 12:30:33 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	point_hex_help(int *i, char *res, char *buf, void *a)
{
	while (i[0] >= 0)
	{
		buf[3 - (i[0] % 4)] = ((*(long long *)a >> i[0]) & 1) + '0';
		buf[4] = '\0';
		if (!(i[0] % 4))
			res[++i[1]] = hex_intc(buf, 0);
		--i[0];
	}
}

void	octa_int_help(int ltype, int *i, char *res, char *buf)
{
	i[0] = ltype - 1;
	i[1] = -1;
	ft_memset(res, '0', 22);
	ft_memset(buf, '0', 3);
}

void	hex_oct_main_help(char ho, int ltype, long long a, char **ptr)
{
	if (ho == 'X' || ho == 'x')
	{
		(ltype == -1) ? ltype = 1 : 0;
		(*ptr) = hex_int(&a, 'x' - ho, 32 + 32 * ltype);
	}
	else if (ho == 'o')
	{
		(ltype == -2) ? ltype = 0 : 0;
		(ltype == -1) ? ltype = 0 : 0;
		(*ptr) = octa_int(&a, 32 + 32 * ltype);
	}
	else
		(*ptr) = bit_out(&a);
}

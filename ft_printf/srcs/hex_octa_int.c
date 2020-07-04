/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_octa_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:18:02 by btheia            #+#    #+#             */
/*   Updated: 2019/11/02 20:45:09 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	hex_intc(char *s, int p)
{
	char c;

	(!(*(int*)s ^ *(int*)"0000")) ? c = '0' : 0;
	(!(*(int*)s ^ *(int*)"0001")) ? c = '1' : 0;
	(!(*(int*)s ^ *(int*)"0010")) ? c = '2' : 0;
	(!(*(int*)s ^ *(int*)"0011")) ? c = '3' : 0;
	(!(*(int*)s ^ *(int*)"0100")) ? c = '4' : 0;
	(!(*(int*)s ^ *(int*)"0101")) ? c = '5' : 0;
	(!(*(int*)s ^ *(int*)"0110")) ? c = '6' : 0;
	(!(*(int*)s ^ *(int*)"0111")) ? c = '7' : 0;
	(!(*(int*)s ^ *(int*)"1000")) ? c = '8' : 0;
	(!(*(int*)s ^ *(int*)"1001")) ? c = '9' : 0;
	(!(*(int*)s ^ *(int*)"1010")) ? c = 'a' - p : 0;
	(!(*(int*)s ^ *(int*)"1011")) ? c = 'b' - p : 0;
	(!(*(int*)s ^ *(int*)"1100")) ? c = 'c' - p : 0;
	(!(*(int*)s ^ *(int*)"1101")) ? c = 'd' - p : 0;
	(!(*(int*)s ^ *(int*)"1110")) ? c = 'e' - p : 0;
	(!(*(int*)s ^ *(int*)"1111")) ? c = 'f' - p : 0;
	return (c);
}

char	*point_hex(void *a, int prs)
{
	char	res[17];
	char	buf[5];
	char	r[17 + prs];
	int		i[2];

	i[0] = 63;
	i[1] = 0;
	ft_memset(res, '0', 17);
	point_hex_help(i, res, buf, a);
	res[++i[1]] = 0;
	i[1] = 0;
	while (res[i[1]] == '0')
		++i[1];
	ft_memset(r, '0', 17 + prs);
	r[0] = '0';
	r[1] = 'x';
	if ((size_t)prs > ft_strlen(res + i[1]))
		ft_strcpy(r + 2 + prs - ft_strlen(res + i[1]), res + i[1]);
	else
		ft_strcpy(r + 2, res + i[1]);
	return (ft_strdup(r));
}

char	*hex_int(void *a, int p, int type)
{
	char	res[17];
	char	buf[5];
	int		j;
	int		i;

	i = type - 1;
	j = -1;
	ft_memset(res, '0', 16);
	while (i >= 0)
	{
		buf[3 - (i % 4)] = ((*(__uint128_t *)a >> i) & 1) + '0';
		buf[4] = '\0';
		if (!(i % 4))
			res[++j] = hex_intc(buf, p);
		i--;
	}
	(type == 32) ? (i = 7) : 0;
	(type != 32) ? (i = 15) : 0;
	res[++j] = 0;
	j = 0;
	while (res[j] == '0' && j < i)
		j++;
	return (ft_strdup(res + j));
}

char	*octa_int(void *a, int ltype)
{
	char	res[23];
	char	buf[4];
	int		i[2];

	octa_int_help(ltype, i, res, buf);
	while (i[0] >= 0)
	{
		buf[2 - (i[0] % 3)] = ((*(__uint128_t *)a >> i[0]) & 1) + '0';
		buf[3] = '\0';
		if (!(i[0] % 3))
		{
			res[++i[1]] = octa_intc(buf);
			help_octa1(buf);
		}
		--i[0];
	}
	res[++i[1]] = 0;
	(ltype == 32) ? (i[0] = 10) : 0;
	(ltype != 32) ? (i[0] = 21) : 0;
	i[1] = 0;
	i[0] = ft_strlen(res) - 1;
	while (res[i[1]] == '0' && i[1] < i[0])
		++i[1];
	return (ft_strdup(res + i[1]));
}

char	*hex_oct_main(va_list elem, t_param *f_p_s, char ho, int ltype)
{
	long long	a;
	char		*ptr;

	ptr = NULL;
	if (ltype == 1)
		a = va_arg(elem, long long);
	else if (ltype == -1)
	{
		a = (unsigned char)va_arg(elem, long long);
		if (a == -1)
			a = 255;
	}
	else if (ltype == -2)
		a = (unsigned short)va_arg(elem, long long);
	else
	{
		a = va_arg(elem, long long);
		if (a == -1)
			a = 4294967295;
	}
	hex_oct_main_help(ho, ltype, a, &ptr);
	(*f_p_s).len = ft_strlen(ptr);
	ft_write_tail_xo(f_p_s, ptr, ho);
	return (ptr);
}

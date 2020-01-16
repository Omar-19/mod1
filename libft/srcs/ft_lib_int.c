/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:46:09 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/07 11:46:12 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_result_len_int(t_param *f_p_s)
{
	int i;

	i = 0;
	(f_p_s->is_pres) ? (f_p_s->is_zero = 0) : 0;
	f_p_s->result = f_p_s->len;
	if (f_p_s->precision > f_p_s->result)
		f_p_s->result = f_p_s->precision;
	if (f_p_s->width > f_p_s->result)
		f_p_s->result = f_p_s->width;
	if ((f_p_s->result == f_p_s->precision) && f_p_s->is_plus)
		i = 1;
	((f_p_s->precision = f_p_s->precision - f_p_s->len + f_p_s->is_plus) > 0) ?
		0 : (f_p_s->precision = 0);
	((f_p_s->width = f_p_s->result - f_p_s->len - f_p_s->precision) > 0) ?
		0 : (f_p_s->width = 0);
	f_p_s->result += i;
}

void		ft_write_no_min_int(t_param *f_p_s, char *ptr, char *str[2])
{
	if (f_p_s->is_space && !f_p_s->is_plus)
	{
		write(1, " ", 1);
		(f_p_s->width) ? 0 : (++f_p_s->result);
		--f_p_s->width;
	}
	(f_p_s->is_zero) ? 0 : (write(1, str[1], f_p_s->width));
	(f_p_s->is_plus) ? ((write(1, ptr++, 1)) && --f_p_s->len) : 0;
	(f_p_s->is_zero) ? (write(1, str[1], f_p_s->width)) : 0;
	write(1, str[0], f_p_s->precision);
	write(1, ptr, f_p_s->len);
}

void		ft_write_min_int(t_param *f_p_s, char *ptr, char *str[2])
{
	if (f_p_s->is_space && !f_p_s->is_plus)
	{
		write(1, " ", 1);
		++f_p_s->result;
		--f_p_s->width;
	}
	(f_p_s->is_plus) ? ((write(1, ptr++, 1)) && --f_p_s->len) : 0;
	write(1, str[0], f_p_s->precision);
	write(1, ptr, f_p_s->len);
	write(1, str[1], f_p_s->width);
}

void		ft_write_tail_int(t_param *f_p_s, char *ptr)
{
	char *str[2];

	str[0] = ft_strnew_char(f_p_s->precision, '0');
	(f_p_s->is_zero && !f_p_s->is_minus) ?
		(str[1] = ft_strnew_char(f_p_s->width, '0')) :
		(str[1] = ft_strnew_char(f_p_s->width, ' '));
	(f_p_s->is_minus) ? (ft_write_min_int(f_p_s, ptr, str)) :
		(ft_write_no_min_int(f_p_s, ptr, str));
	free(str[0]);
	free(str[1]);
}

void		itoa_flag_handling(long long int value_i,
	unsigned long long value_u, t_param *f_p_s, t_intp *par)
{
	par->flag = 0;
	f_p_s->len = 0;
	if (f_p_s->is_plus)
	{
		f_p_s->is_space = 0;
		par->flag = 3;
		++(f_p_s->len);
	}
	if (value_i < 0)
	{
		(par->flag != 3) ? (++f_p_s->len) : 0;
		f_p_s->is_plus = 1;
		par->flag = 1;
		par->val[0] = -value_i;
	}
	else if (value_i > 0)
		par->val[0] = value_i;
	else
		par->val[0] = value_u;
}

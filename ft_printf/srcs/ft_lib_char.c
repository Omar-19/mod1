/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:32 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/02 19:25:59 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_result_len_str(t_param *f_p_s)
{
	(f_p_s->is_pres && !f_p_s->precision) ? (f_p_s->len = 0) : 0;
	(f_p_s->is_pres && (f_p_s->precision < f_p_s->len)) ?
		(f_p_s->len = f_p_s->precision) : 0;
	f_p_s->result = f_p_s->len;
	if (f_p_s->width > f_p_s->result)
		f_p_s->result = f_p_s->width;
	((f_p_s->width = f_p_s->result - f_p_s->len) > 0) ?
		0 : (f_p_s->width = 0);
}

void		ft_result_len_char(t_param *f_p_s)
{
	f_p_s->result = f_p_s->len;
	if (f_p_s->width > f_p_s->result)
		f_p_s->result = f_p_s->width;
}

void		ft_write_tail_str(t_param *f_p_s, char *ptr)
{
	char *str;

	str = NULL;
	ft_result_len_str(f_p_s);
	if (!f_p_s->is_minus && f_p_s->is_zero)
		str = ft_strnew_char(f_p_s->width, '0');
	else
		str = ft_strnew_char(f_p_s->width, ' ');
	if (f_p_s->is_minus)
	{
		write(1, ptr, f_p_s->len);
		write(1, str, f_p_s->width);
	}
	else
	{
		write(1, str, f_p_s->width);
		write(1, ptr, f_p_s->len);
	}
	if (str)
		free(str);
}

void		ft_write_tail_char(t_param *f_p_s, char c)
{
	char *str;

	str = NULL;
	ft_result_len_char(f_p_s);
	if (!f_p_s->is_minus && f_p_s->is_zero)
		str = ft_strnew_char((f_p_s->result - f_p_s->len), '0');
	else
		str = ft_strnew_char((f_p_s->result - f_p_s->len), ' ');
	if (f_p_s->is_minus)
	{
		write(1, &c, 1);
		write(1, str, (f_p_s->result - f_p_s->len));
	}
	else
	{
		write(1, str, (f_p_s->result - f_p_s->len));
		write(1, &c, 1);
	}
	if (str)
		free(str);
}

void		ft_write_tail_percent(t_param *f_p_s)
{
	char *str;

	str = NULL;
	f_p_s->len = 1;
	if (f_p_s->width)
		f_p_s->result = f_p_s->width;
	else
	{
		f_p_s->result = 1;
		f_p_s->width = 1;
	}
	(f_p_s->is_zero && !f_p_s->is_minus) ?
		(str = ft_strnew_char(f_p_s->width, '0')) :
		(str = ft_strnew_char(f_p_s->width, ' '));
	(f_p_s->is_minus) ? (str[0] = '%') :
		(str[f_p_s->width - 1] = '%');
	write(1, str, f_p_s->width);
	if (str)
		free(str);
}

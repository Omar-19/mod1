/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_hex_octa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:35:04 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/02 19:32:14 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_xo_write_min(t_param *f_p_s, char *ptr, char ho, char *str[2])
{
	int a;

	a = 0;
	if (f_p_s->is_hash)
	{
		a = 2;
		(ho == 'x') ? (write(1, "0x", 2) && (f_p_s->width -= 2)) : 0;
		(ho == 'X') ? (write(1, "0X", 2) && (f_p_s->width -= 2)) : 0;
		(f_p_s->width < 0) ? ((f_p_s->result += f_p_s->width) &&
			(f_p_s->width = 0)) : 0;
	}
	a = a + f_p_s->precision + f_p_s->len + f_p_s->width;
	write(1, str[0], f_p_s->precision);
	write(1, ptr, f_p_s->len);
	write(1, str[1], f_p_s->width);
	f_p_s->result = a;
}

void	ft_xo_write(t_param *f_p_s, char *ptr, char ho, char *str[2])
{
	int a;

	a = 0;
	if (f_p_s->is_hash)
	{
		f_p_s->width -= 2;
		if (f_p_s->width < 0)
		{
			f_p_s->result += f_p_s->width;
			f_p_s->width = 0;
		}
	}
	a += f_p_s->width;
	(f_p_s->is_zero) ? 0 : write(1, str[1], f_p_s->width);
	if (f_p_s->is_hash)
	{
		a += 2;
		(ho == 'x') ? write(1, "0x", 2) : 0;
		(ho == 'X') ? write(1, "0X", 2) : 0;
	}
	(f_p_s->is_zero) ? (write(1, str[1], f_p_s->width)) : 0;
	a = a + f_p_s->precision + f_p_s->len;
	write(1, str[0], f_p_s->precision);
	write(1, ptr, f_p_s->len);
	f_p_s->result = a;
}

void	ft_free_str(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

void	hhelp_hex_oc(t_param *f_p_s, char *ptr, char ho)
{
	if (f_p_s->is_hash && (ho == 'o'))
	{
		f_p_s->is_hash = 0;
		if (f_p_s->len >= f_p_s->precision)
			(*ptr != '0') ? (f_p_s->precision = f_p_s->len + 1) : 0;
	}
}

void	ft_write_tail_xo(t_param *f_p_s, char *ptr, char ho)
{
	char	*str[2];

	if (f_p_s->is_pres && (f_p_s->precision == 0))
	{
		f_p_s->is_pres = 0;
		if (*ptr == '0')
		{
			f_p_s->len = 0;
			ptr = "";
		}
	}
	hhelp_hex_oc(f_p_s, ptr, ho);
	ft_result_len_xo(f_p_s);
	if (f_p_s->is_hash && (*ptr == '0'))
		f_p_s->is_hash = 0;
	(f_p_s->is_zero) ?
		(str[1] = ft_strnew_char(f_p_s->width, '0')) :
			(str[1] = ft_strnew_char(f_p_s->width, ' '));
	str[0] = ft_strnew_char(f_p_s->precision, '0');
	if (f_p_s->is_minus)
		ft_xo_write_min(f_p_s, ptr, ho, str);
	else
		ft_xo_write(f_p_s, ptr, ho, str);
	ft_free_str(str[0], str[1]);
}

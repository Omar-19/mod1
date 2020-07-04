/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_proc_help1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:18:53 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/04 13:18:56 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				form_spec_help01(const char *str, va_list elem,
	t_param *f_p_s, size_t *i)
{
	f_p_s->is_pres = 1;
	if (*(str + ++(i[1])) == '*')
	{
		(*f_p_s).precision = va_arg(elem, int);
		if (f_p_s->precision < 0)
		{
			f_p_s->precision = f_p_s->width;
			(f_p_s->precision == 0) ? (f_p_s->is_pres = 0) : 0;
		}
	}
	else
		(*f_p_s).precision = ft_atoi_n(str + (i[1]), &(i[1]));
}

int					read_variable_int(const char *str, size_t len,
	va_list elem, t_param *f_p_s)
{
	char	*ptr;

	ptr = NULL;
	if (ft_strstr_num(str, "d\0", len) || ft_strstr_num(str, "i\0", len))
		ptr = read_help_1(str, len, elem, f_p_s);
	else if (ft_strstr_num(str, "u\0", len) || ft_strstr_num(str, "U\0", len))
	{
		if (ft_strstr_num(str, "ll\0", len) || ft_strstr_num(str, "U\0", len))
			ptr = ft_itoa_d(0, va_arg(elem, unsigned long long int), f_p_s, 1);
		else if (ft_strstr_num(str, "l\0", len) ||
			(ft_strstr_num(str, "j\0", len)))
			ptr = ft_itoa_d(0, va_arg(elem, unsigned long int), f_p_s, 1);
		else if (ft_strstr_num(str, "hh\0", len))
			ptr = ft_itoa_d(0, (unsigned char)va_arg(elem, int), f_p_s, 1);
		else if (ft_strstr_num(str, "h\0", len))
			ptr = ft_itoa_d(0, (unsigned short int)va_arg(elem, int), f_p_s, 1);
		else
			ptr = ft_itoa_d(0, va_arg(elem, unsigned int), f_p_s, 1);
	}
	else
		return (0);
	if (ptr)
		free(ptr);
	return ((*f_p_s).result);
}

int					read_variable_int1(const char *str, size_t len,
	va_list elem, t_param *form_place_spc)
{
	char	*ptr;
	size_t	i[2];

	i[0] = len;
	ptr = NULL;
	if (ft_strstr_num(str, "x\0", len) && (i[1] = 'x'))
		ptr = read_hex_help1(str, i, elem, form_place_spc);
	else if (ft_strstr_num(str, "X\0", len) && (i[1] = 'X'))
		ptr = read_hex_help1(str, i, elem, form_place_spc);
	else if (ft_strstr_num(str, "o\0", len) && (i[1] = 'o'))
		ptr = read_hex_help1(str, i, elem, form_place_spc);
	else if (ft_strstr_num(str, "b\0", len) && (i[1] = 'b'))
		ptr = read_hex_help1(str, i, elem, form_place_spc);
	else
		return (0);
	if (ptr)
		free(ptr);
	return (form_place_spc->result);
}

int					read_variable_char(const char *str, size_t len,
	va_list elem, t_param *f_p_s)
{
	char	*ptr;

	ptr = NULL;
	if (ft_strstr_num(str, "c\0", len))
	{
		f_p_s->len = 1;
		ft_write_tail_char(f_p_s, (char)va_arg(elem, int));
		return (f_p_s->result);
	}
	else if (ft_strstr_num(str, "s\0", len))
	{
		ptr = va_arg(elem, char*);
		if (!ptr)
			check_null_ptr(&ptr, f_p_s);
		f_p_s->len = ft_strlen(ptr);
		ft_write_tail_str(f_p_s, ptr);
		return (f_p_s->result);
	}
	else if (ft_strstr_num(str, "p\0", len))
	{
		read_char_help(ptr, elem, f_p_s);
		return (f_p_s->result);
	}
	return (0);
}

int					read_variable_percent(const char *str,
	size_t len, t_param *form_place_spc)
{
	form_place_spc->len = 1;
	if (ft_strstr_num(str, "%\0", len))
		ft_write_tail_percent(form_place_spc);
	else
		return (0);
	return (form_place_spc->result);
}

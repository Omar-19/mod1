/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_proc_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:18:59 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/11 19:08:50 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				help_okrug_zero(int *i, char *s, int key, char *p)
{
	if (key && !(i[1] && (s[i[0]] == '2' || s[i[0]] == '4'
					|| s[i[0]] == '6' || s[i[0]] == '8')))
	{
		s[i[0]] += 1;
		return ;
	}
	i[1] = 0;
	i[0] = p - s + 2;
}

void				check_null_ptr(char **ptr, t_param *f_p_s)
{
	(f_p_s->is_pres && !f_p_s->precision) ? (*ptr = "") :
		(*ptr = "(null)");
}

static inline char	*help_read_float(const char *str, size_t len,
	va_list elem, t_param *form_place_spc)
{
	char			*ptr;
	t_double		d;
	int				sign;

	ptr = NULL;
	if ((*form_place_spc).precision == 0 && !ft_strstr_num(str, ".0\0", len))
		(*form_place_spc).precision = 6;
	if (ft_strstr_num(str, "Lf\0", len))
	{
		d.numld = va_arg(elem, long double);
		ptr = new_float_ld(d, (*form_place_spc).precision);
	}
	else if (ft_strstr_num(str, "f\0", len))
	{
		d.numd = va_arg(elem, double);
		ptr = new_float_d(d, (*form_place_spc).precision);
	}
	else if (ft_strstr_num(str, "Le\0", len))
	{
		d.numld = va_arg(elem, long double);
		ptr = float_lde(d, (*form_place_spc).precision, &sign);
	}
	return (ptr);
}

static inline char	*help_read_float1(const char *str, size_t len,
	va_list elem, t_param *form_place_spc)
{
	char			*ptr;
	t_double		d;
	int				sign;

	ptr = NULL;
	if (ft_strstr_num(str, "e\0", len))
	{
		d.numd = va_arg(elem, double);
		ptr = float_de(d, (*form_place_spc).precision, &sign);
	}
	else if (ft_strstr_num(str, "Lg\0", len))
	{
		d.numld = va_arg(elem, long double);
		ptr = float_ldg(d, (*form_place_spc).precision, &sign);
	}
	else if (ft_strstr_num(str, "g\0", len))
	{
		d.numd = va_arg(elem, double);
		ptr = float_dg(d, (*form_place_spc).precision, &sign);
	}
	return (ptr);
}

int					read_variable_float(const char *str, size_t len,
	va_list elem, t_param *form_place_spc)
{
	char			*ptr;

	ptr = help_read_float(str, len, elem, form_place_spc);
	if (ptr == NULL)
		ptr = help_read_float1(str, len, elem, form_place_spc);
	if (ptr == NULL)
		return (0);
	(*form_place_spc).len = ft_strlen(ptr);
	if (form_place_spc->is_hash && form_place_spc->is_pres &&
		!form_place_spc->precision)
	{
		*(ptr + form_place_spc->len) = '.';
		++(form_place_spc->len);
	}
	ft_result_len_float(form_place_spc, *ptr);
	ft_flag_correction_1(form_place_spc);
	ft_write_tail(form_place_spc, *ptr, ptr);
	if (ptr)
		free(ptr);
	return ((*form_place_spc).result);
}

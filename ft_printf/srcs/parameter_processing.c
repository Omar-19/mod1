/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:07 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/03 13:26:07 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_atoi_n(const char *str, size_t *j)
{
	long	number;

	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		++(*j);
		if (number < 0 && number < number * 10)
			return (0);
		if (number > 0 && number > number * 10)
			return (-1);
		number = number * 10 + 1 * (*str - '0');
		++str;
	}
	return (number);
}

void		par_help3(const char *str, size_t *i,
	t_param *f_p_s, va_list elem)
{
	f_p_s->is_width = 0;
	f_p_s->width = 0;
	if (*(str + (i[1])) == '*')
	{
		(*f_p_s).width = va_arg(elem, int);
		if (f_p_s->width < 0)
		{
			f_p_s->width *= -1;
			f_p_s->is_minus = 1;
		}
		++(i[1]);
	}
	if (*(str + (i[1])) >= '0' && *(str + (i[1])) <= '9')
		(*f_p_s).width = ft_atoi_n(str + (i[1]), &(i[1]));
}

char		*read_help_1(const char *str, size_t len,
	va_list elem, t_param *f_p_s)
{
	char	*ptr;

	ptr = NULL;
	if (ft_strstr_num(str, "j\0", len) || ft_strstr_num(str, "z\0", len) ||
		ft_strstr_num(str, "ll\0", len))
		ptr = ft_itoa_d(va_arg(elem, long long int), 0, f_p_s, 0);
	else if (ft_strstr_num(str, "l\0", len))
		ptr = ft_itoa_d(va_arg(elem, long int), 0, f_p_s, 0);
	else if (ft_strstr_num(str, "hh\0", len))
		ptr = ft_itoa_d((signed char)va_arg(elem, int), 0, f_p_s, 0);
	else if (ft_strstr_num(str, "h\0", len))
		ptr = ft_itoa_d((short int)va_arg(elem, int), 0, f_p_s, 0);
	else
		ptr = ft_itoa_d(va_arg(elem, int), 0, f_p_s, 0);
	return (ptr);
}

int			ft_param_processing(const char *str,
	size_t len, va_list elem)
{
	int		l;
	t_param	form_place_spc;

	if (ft_strstr_num(str, "Z\0", len))
	{
		write(1, "Z", 1);
		return (1);
	}
	ft_format_specification_description(str, len, elem, &form_place_spc);
	if ((l = read_variable_percent(str, len, &form_place_spc)))
		return (l);
	else if ((l = read_variable_int1(str, len, elem, &form_place_spc)))
		return (l);
	else if ((l = read_variable_char(str, len, elem, &form_place_spc)))
		return (l);
	else if ((l = read_variable_int(str, len, elem, &form_place_spc)))
		return (l);
	else
	{
		ft_flag_correction3(&form_place_spc);
		if ((l = read_variable_float(str, len, elem, &form_place_spc)))
			return (l);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_proc_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:18:43 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/04 13:18:49 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static inline int	ft_is_flag(const char c)
{
	return (!(ft_strchr("#0-+ ", c) == NULL));
}

static inline void	ft_null_f_p_s(t_param *f_p_s, size_t *i, size_t *j)
{
	*i = 0;
	*j = 0;
	f_p_s->is_hash = 0;
	f_p_s->is_minus = 0;
	f_p_s->is_plus = 0;
	f_p_s->is_pres = 0;
	f_p_s->is_space = 0;
	f_p_s->is_zero = 0;
	f_p_s->is_width = 1;
}

static inline void	par_help2(size_t *i, t_param *f_p_s,
	size_t len, const char *str)
{
	while ((i[0]) < len)
	{
		if (*(str + (i[0])) == '+' || *(str + (i[0])) == '-')
		{
			f_p_s->is_plus = 1;
			*((*f_p_s).flags + (i[2])) = *(str + (i[0]));
			*((*f_p_s).flags + (i[2]) + 1) = '\0';
			++(i[2]);
		}
		if (*(str + (i[0])) == '#')
		{
			f_p_s->is_hash = 1;
			*((*f_p_s).flags + (i[2])) = *(str + (i[0]));
			*((*f_p_s).flags + (i[2]) + 1) = '\0';
			++(i[2]);
		}
		++(i[0]);
	}
}

static inline void	par_help(t_param *f_p_s,
	const char *str, size_t i, size_t *j)
{
	(*(str + i) == ' ') ? (f_p_s->is_space = 1) : 0;
	(*(str + i) == '+') ? (f_p_s->is_plus = 1) : 0;
	(*(str + i) == '-') ? (f_p_s->is_minus = 1) : 0;
	(*(str + i) == '#') ? (f_p_s->is_hash = 1) : 0;
	(*(str + i) == '0') ? (f_p_s->is_zero = 1) : 0;
	*((*f_p_s).flags + *j) = *(str + i);
	*((*f_p_s).flags + *j + 1) = '\0';
	++(*j);
}

void				ft_format_specification_description(const char *str,
	size_t len, va_list elem, t_param *f_p_s)
{
	size_t	i[3];

	ft_null_f_p_s(f_p_s, &(i[0]), &(i[1]));
	while (ft_is_flag(*(str + (i[0]))) && (i[0]) < len)
	{
		if ((i[0]) == 0 || !ft_strchr((*f_p_s).flags, *(str + (i[0]))))
			par_help(f_p_s, str, (i[0]), &(i[1]));
		++(i[0]);
	}
	(i[2]) = (i[1]);
	(i[1]) = (i[0]);
	par_help2(i, f_p_s, len, str);
	par_help3(str, i, f_p_s, elem);
	if (*(str + (i[1])) == '.')
		form_spec_help01(str, elem, f_p_s, i);
	else
		(*f_p_s).precision = 0;
}

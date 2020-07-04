/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:32 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/07 20:57:01 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_write_min(char *str, int i, char *ptr, t_param *f_p_s)
{
	if (ptr[0] == '-')
	{
		write(1, ptr, (*f_p_s).len);
		write(1, str, i);
	}
	else if (str[i - 1] == '+')
	{
		write(1, "+", 1);
		write(1, ptr, (*f_p_s).len);
		write(1, str, i - 1);
	}
	else
	{
		if (ft_strchr((*f_p_s).flags, ' '))
		{
			write(1, " ", 1);
			--i;
		}
		write(1, ptr, (*f_p_s).len);
		write(1, str, i);
	}
}

void		ft_write1(t_param *f_p_s, char c, char *ptr)
{
	char *ci;

	ci = f_p_s->flags;
	if (ft_strchr((const char*)ci, '+') != NULL && c != '-')
	{
		++(f_p_s->result);
		write(1, "+", 1);
	}
	else if (f_p_s->is_space)
	{
		++(f_p_s->result);
		write(1, " ", 1);
	}
	write(1, ptr, (*f_p_s).len);
}

void		ft_write2(t_param *f_p_s, char c, char *ptr, int i)
{
	char *str;

	if (c == '-')
	{
		++i;
		--f_p_s->len;
		++ptr;
	}
	str = ft_strnew_char(i, '0');
	if (f_p_s->is_plus)
	{
		if (c == '-')
			str[0] = '-';
		else
			str[0] = '+';
	}
	else if (f_p_s->is_space)
		str[0] = ' ';
	write(1, str, i);
	write(1, ptr, (*f_p_s).len);
	free(str);
}

void		ft_write3(t_param *f_p_s, char c, char *ptr, int i)
{
	char *str;

	str = ft_strnew_char(i, ' ');
	if (f_p_s->is_plus)
	{
		if (c == '-')
			str[i - 1] = ' ';
		else
			str[i - 1] = '+';
	}
	if (f_p_s->is_minus)
		ft_write_min(str, i, ptr, f_p_s);
	else
	{
		write(1, str, i);
		write(1, ptr, (*f_p_s).len);
	}
	free(str);
}

void		ft_write_tail(t_param *f_p_s, char c, char *ptr)
{
	int		i;

	if (f_p_s->len == f_p_s->result)
	{
		ft_write1(f_p_s, c, ptr);
		return ;
	}
	i = f_p_s->result - f_p_s->len;
	if (c == '-')
		ft_flag_correction(f_p_s);
	if (f_p_s->is_zero)
		ft_write2(f_p_s, c, ptr, i);
	else
		ft_write3(f_p_s, c, ptr, i);
}

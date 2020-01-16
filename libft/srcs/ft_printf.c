/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:49 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/11 19:41:18 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void		ft_write_str(const char *str, size_t len)
{
	write(1, str, len);
}

inline int	ft_is_conversion(const char c)
{
	return (!(ft_strchr("diuoxXfFeEgGaAcsSpbnZU%", c) == NULL));
}

int			printf_help3(size_t *i, const char **str)
{
	if (((i[2]) = (str[0]) + (i[0]) - (str[1])))
	{
		i[1] += (i[2]);
		ft_write_str((str[1]), (i[2]));
	}
	return (i[1]);
}

int			print_elem(const char *format, va_list elem)
{
	const char	*str[2];
	size_t		i[3];

	(str[0]) = format;
	(str[1]) = (str[0]);
	printf_help(i, &(i[2]));
	while ((str[0])[(i[0])])
	{
		if ((str[0])[(i[0])] == '%')
		{
			printf_help1(&(i[2]), &(str[1]), &(str[0]), i);
			if (!(str[0])[(i[0])])
				return (i[1]);
			while (!(ft_is_conversion((str[0])[(i[0])])))
			{
				if (!(str[0])[++(i[0])])
					return (0);
			}
			printf_help2(i, str, elem);
			(str[1]) = (str[0]) + ++(i[0]);
			continue;
		}
		++(i[0]);
	}
	return (printf_help3(i, str));
}

int			ft_printf(const char *format, ...)
{
	va_list	elem;
	int		result;

	va_start(elem, format);
	result = print_elem(format, elem);
	va_end(elem);
	return (result);
}

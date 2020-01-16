/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:33:05 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/02 18:21:02 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static inline int	ft_is_length(const char c)
{
	return (!(ft_strchr("hhllLzjt", c) == NULL));
}

static inline int	ft_is_flag(const char c)
{
	return (!(ft_strchr("#0-+' ", c) == NULL));
}

static inline int	ft_is_num(const char c)
{
	return (c >= '0' && c <= '9');
}

int					ft_is_valid_param(const char c)
{
	return (ft_is_conversion(c) || ft_is_flag(c) ||
			ft_is_num(c) || ft_is_length(c));
}

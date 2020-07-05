/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:28:24 by fyuko             #+#    #+#             */
/*   Updated: 2020/07/05 13:06:13 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new_l)
{
	if (alst != NULL && new_l != NULL)
	{
		new_l->next = *alst;
		*alst = new_l;
	}
}

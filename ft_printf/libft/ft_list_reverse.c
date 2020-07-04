/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:56:45 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/11 23:05:20 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *p1;
	t_list *p2;
	t_list *p3;

	if (*begin_list == 0 || (*begin_list)->next == 0)
		return ;
	p1 = *begin_list;
	p2 = p1->next;
	p3 = p2->next;
	p1->next = (void *)0;
	while (p3)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}
	p2->next = p1;
	*begin_list = p2;
}

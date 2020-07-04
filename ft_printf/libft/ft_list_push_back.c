/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:35:36 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/11 23:04:10 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list,
		void const *content, size_t content_size)
{
	t_list *a;

	if (*begin_list == 0)
	{
		*begin_list = ft_lstnew(content, content_size);
		return ;
	}
	a = *begin_list;
	while (a->next)
		a = a->next;
	a->next = ft_lstnew(content, content_size);
}

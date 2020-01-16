/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:54:45 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/11 23:04:18 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list,
		void const *content, size_t content_size)
{
	t_list *a;

	a = ft_lstnew(content, content_size);
	a->next = *begin_list;
	*begin_list = a;
}

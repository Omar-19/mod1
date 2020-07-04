/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:58:59 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/11 20:19:30 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nxt;
	t_list *tmp;

	if (alst != NULL && del != NULL)
	{
		nxt = *alst;
		while (nxt)
		{
			tmp = nxt->next;
			ft_lstdelone(&nxt, del);
			nxt = tmp;
		}
		*alst = NULL;
	}
}

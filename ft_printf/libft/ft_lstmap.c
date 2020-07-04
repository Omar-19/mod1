/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:01:07 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/11 20:34:08 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clean(t_list *lst)
{
	t_list *p;

	while (lst)
	{
		p = lst->next;
		free(lst->content);
		free(lst->next);
		lst->content = NULL;
		lst->next = NULL;
		free(lst);
		lst = NULL;
		lst = p;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;
	t_list *lstcpy;

	if (lst == NULL || f == NULL)
		return (NULL);
	ptr = (*f)(lst);
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	lstcpy = ptr;
	while (lst->next)
	{
		lst = lst->next;
		ptr->next = (*f)(lst);
		if (ptr->next == NULL)
		{
			ft_clean(lstcpy);
			return (NULL);
		}
		ptr = ptr->next;
	}
	ptr->next = NULL;
	return (lstcpy);
}

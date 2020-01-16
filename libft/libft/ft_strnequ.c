/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:56:22 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/08 16:06:04 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (s1 != NULL && s2 != NULL && n > 0)
	{
		while (s1[i] == s2[i] && s1[i] != '\0' && n > 0)
		{
			++i;
			--n;
		}
		if (n == 0 || (s1[i] == '\0' && s2[i] == '\0'))
			return (1);
		else
			return (0);
	}
	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (1);
	else
		return (0);
}

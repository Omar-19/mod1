/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:35:11 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/08 15:55:53 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] == s2[i] && s1[i] != '\0')
			i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
		else
			return (0);
	}
	if (s1 == NULL && s2 == NULL)
		return (1);
	else
		return (0);
}

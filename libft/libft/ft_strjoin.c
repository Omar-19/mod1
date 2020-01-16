/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:45:14 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/10 21:15:27 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (s1 != NULL && s2 != NULL)
	{
		if (!(str = (char *)malloc(sizeof(char)
						* (ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcpy(str + ft_strlen(s1), s2);
		return (str);
	}
	return (NULL);
}

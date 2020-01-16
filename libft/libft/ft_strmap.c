/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:24:30 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/10 21:14:20 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		max;
	char	*str;

	i = 0;
	if (s != NULL && f != NULL)
	{
		max = ft_strlen(s);
		if (!(str = (char *)malloc(sizeof(char) * max + 1)))
			return (NULL);
		while (i < max)
		{
			str[i] = (*f)(s[i]);
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

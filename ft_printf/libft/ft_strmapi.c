/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:27:08 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/08 15:35:03 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	max;
	char			*str;

	i = 0;
	if (s != NULL && f != NULL)
	{
		max = ft_strlen(s);
		if (!(str = (char *)malloc(sizeof(char) * max + 1)))
			return (NULL);
		while (i < max)
		{
			str[i] = (*f)(i, s[i]);
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

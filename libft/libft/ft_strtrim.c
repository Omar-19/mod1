/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:22:57 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/10 21:15:43 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		min;
	int		max;
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	min = i;
	while (s[i] != '\0')
		++i;
	--i;
	while (min <= i && i > 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		--i;
	max = i + 1;
	if (!(str = (char *)malloc(sizeof(char) * (max - min) + 1)))
		return (NULL);
	str[max - min] = '\0';
	ft_strncpy(str, (s + min), (max - min));
	return (str);
}

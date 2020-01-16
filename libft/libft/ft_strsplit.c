/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:36:26 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/10 21:16:09 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int i;

	i = 0;
	if (*s == '\0')
		return (1);
	while (*s != '\0')
	{
		while (*s == c)
			++s;
		if (*s != '\0')
		{
			++i;
			while (*s != c && *s != '\0')
				++s;
		}
	}
	if (i == 0)
		return (1);
	return (i);
}

static int	word_length(char const *s, char c, int *i)
{
	int j;

	j = 0;
	while (s[*i] == c)
		++(*i);
	if (s[*i] != '\0')
		while (s[*i] != c && s[*i] != '\0')
		{
			++j;
			++(*i);
		}
	return (j);
}

static void	writing_new_str(char **str, char const *s, char c)
{
	int i;
	int j;

	i = 0;
	while (*s == c)
		++s;
	if (*s == '\0')
		str[i] = NULL;
	while (*s != '\0')
	{
		j = 0;
		while (*s != c && *s != '\0')
			str[i][j++] = *(s++);
		str[i][j] = '\0';
		++i;
		while (*s == c)
			++s;
	}
}

static void	ft_clean(char **str, int i)
{
	while (i >= 0)
		free(str[i++]);
	free(str);
	str = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	char	**str;

	k = 0;
	if (s == NULL || word_count(s, c) == 0)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * word_count(s, c) + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (!(str[k++] = (char *)malloc(sizeof(char *)
						* word_length(s, c, &i) + 1)))
		{
			ft_clean(str, k - 1);
			return (NULL);
		}
		while (s[i] == c)
			++i;
	}
	str[k] = NULL;
	writing_new_str(str, s, c);
	return (str);
}

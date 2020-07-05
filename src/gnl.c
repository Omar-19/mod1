/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:59:51 by btheia            #+#    #+#             */
/*   Updated: 2020/07/05 10:56:10 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod_h.h"

t_list	*ft_check_list(t_list **head, const int fd)
{
	t_list	*ptr;

	ptr = *head;
	if (!ptr)
	{
		if ((ptr = ft_lstnew("\0", 1)) == NULL)
			return (NULL);
		ptr->content_size = fd;
		*head = ptr;
		return (ptr);
	}
	while (ptr)
	{
		if (ptr->content_size == (size_t)fd)
			return (ptr);
		if (!(ptr->next))
			break ;
		ptr = ptr->next;
	}
	if ((ptr->next = ft_lstnew("\0", 1)) == NULL)
		return (NULL);
	ptr->next->content_size = fd;
	return (ptr->next);
}

int		ft_buf_overwrite(t_list **ptr, char **line)
{
	char	*tmp;
	int		len;

	if (ft_strchr((*ptr)->content, '\n'))
		tmp = ft_strchr((*ptr)->content, '\n');
	else
		tmp = ft_strchr((*ptr)->content, '\0');
	len = (tmp - (char *)(*ptr)->content);
	if (!(*line = (char *)malloc(sizeof(char) * len + 1)))
		return (-1);
	*line = ft_strncpy(*line, (*ptr)->content, len);
	*(*line + len) = '\0';
	len = ft_strlen((*ptr)->content) - len;
	if (len != 0)
		(*ptr)->content = ft_memmove((*ptr)->content, tmp + 1, len);
	else
		(*ptr)->content = ft_memmove((*ptr)->content, tmp, 1);
	return (1);
}

int		ft_read(t_list **ptr, char **line)
{
	int		num_read;
	char	str[BUFF_SIZE + 1];
	char	*tmp;

	while (!ft_strchr((*ptr)->content, '\n'))
	{
		num_read = read((*ptr)->content_size, str, BUFF_SIZE);
		str[num_read] = '\0';
		if (num_read == -1)
			return (-1);
		if (num_read == 0)
			break ;
		if (!(tmp = ft_strjoin((*ptr)->content, str)))
			return (-1);
		free((*ptr)->content);
		(*ptr)->content = tmp;
	}
	if (*((char *)(*ptr)->content) == '\0')
		return (0);
	return (ft_buf_overwrite(ptr, line));
}

void	ft_clean(t_list **head, const int fd, char **line)
{
	t_list	*ptr;
	t_list	*tmp;

	if (line)
		tmp = *head;
	tmp = *head;
	ptr = NULL;
	if (tmp->content_size == (size_t)fd)
	{
		free((*head)->content);
		*head = tmp->next;
		free(tmp);
		return ;
	}
	while (!(tmp->content_size == (size_t)fd))
	{
		ptr = tmp;
		tmp = tmp->next;
	}
	ptr->next = tmp->next;
	free(tmp->content);
	free(tmp);
}

int		gnl(const int fd, char **line)
{
	int				i;
	static t_list	*head;
	t_list			*ptr;

	if (fd < 0 || !line || !(ptr = ft_check_list(&head, fd)))
		return (-1);
	i = ft_read(&ptr, line);
	if (i == -1 || i == 0)
		ft_clean(&head, fd, line);
	return (i);
}

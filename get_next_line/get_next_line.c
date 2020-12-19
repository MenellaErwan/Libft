/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 01:40:54 by emenella          #+#    #+#             */
/*   Updated: 2020/12/01 04:10:58 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_buffer_to_line(t_list *current, char **line, t_list **alst)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (ft_strchr(current->content, '\n'))
	{
		tmp = ft_strdup(current->content);
		while (tmp && tmp[i] != '\n')
			i++;
		j = i + 1;
		while (current->content[i])
			current->content[i++] = '\0';
		*line = ft_strdup(current->content);
		free(current->content);
		if (!(current->content = ft_strdup(&tmp[j])))
			return (-1);
		free(tmp);
		return (1);
	}
	*line = ft_strdup(current->content);
	ft_lstfree(current, alst);
	return (0);
}

void	ft_lstfree(t_list *lst, t_list **alst)
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp && tmp != lst)
	{
		if (tmp->next == lst)
			tmp->next = lst->next;
		tmp = tmp->next;
	}
	if (lst == *alst)
		*alst = lst->next;
	free(lst->content);
	lst->content = NULL;
	free(lst);
	lst = NULL;
}

t_list	*ft_lstchr(int fd, t_list **alst)
{
	t_list *tmp;

	tmp = *alst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	int		j;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(result = malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static t_list	*alst;
	t_list			*current;
	int				readed;

	readed = 0;
	if (!line || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	if (!alst && !(alst = ft_lstnew(fd)))
		return (-1);
	if (!(current = ft_lstchr(fd, &alst)))
	{
		ft_lstadd_back(&alst, fd);
		current = ft_lstchr(fd, &alst);
	}
	while (!ft_strchr(current->content, '\n') && (readed = read(current->fd,
	buffer, BUFFER_SIZE)) > 0)
	{
		buffer[readed] = '\0';
		current->content = ft_strjoin(current->content, buffer);
	}
	return (ft_buffer_to_line(current, line, &alst));
}

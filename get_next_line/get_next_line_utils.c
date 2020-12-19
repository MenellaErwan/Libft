/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:29:28 by emenella          #+#    #+#             */
/*   Updated: 2020/12/02 02:24:06 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

t_list	*ft_lstnew(int fd)
{
	t_list	*list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	list->content = ft_strdup("");
	list->fd = fd;
	list->next = NULL;
	return (list);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

void	ft_lstadd_back(t_list **alst, int fd)
{
	t_list *lstlast;

	lstlast = *alst;
	if (lstlast)
		while (lstlast->next != NULL)
			lstlast = lstlast->next;
	if (lstlast == NULL)
		*alst = ft_lstnew(fd);
	else
		lstlast->next = ft_lstnew(fd);
}

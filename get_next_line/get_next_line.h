/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 01:34:43 by emenella          #+#    #+#             */
/*   Updated: 2020/12/01 04:14:09 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 64

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
	int				fd;
}					t_list;

int					get_next_line(int fd, char **line);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
void				ft_lstadd_back(t_list **alst, int fd);
t_list				*ft_lstnew(int fd);
t_list				*ft_lstchr(int fd, t_list **alst);
t_list				*ft_lstprec(t_list *lst);
int					ft_buffer_to_line(t_list *current,
char **line, t_list **alst);
void				ft_lstfree(t_list *lst, t_list **alst);
int					ft_strlen(char *s);
#endif

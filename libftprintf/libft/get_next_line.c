/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:01:53 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/07 17:56:11 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static	int			ft_find(char **str, t_gnl *head)
{
	char			*tmp;
	int				i;
	size_t			flag;

	i = -1;
	flag = 1;
	tmp = ft_strdup(*str);
	ft_strdel(&(*str));
	while (tmp[++i] != '\n')
	{
		if (tmp[i] == '\0')
		{
			flag = 0;
			break ;
		}
	}
	head->line_buff = ft_strsub(tmp, 0, i);
	if (ft_strchr(&tmp[i], '\n'))
	{
		head->temp = ft_strdup(&tmp[i + flag]);
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

static	int			ft_conct(char *buff, t_gnl *head)
{
	char			*tmp;
	int				res;

	while ((res = read(head->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		tmp = ft_strdup(head->line_buff);
		if (head->line_buff)
			ft_strdel(&head->line_buff);
		head->line_buff = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
		if (ft_strchr(head->line_buff, '\n'))
			break ;
	}
	if (res > 0)
		ft_find(&head->line_buff, head);
	return (res);
}

static	t_gnl		*lst_new(int fd, t_gnl **head)
{
	t_gnl			*list;

	list = *head;
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	if (!(list = malloc(sizeof(t_gnl))))
		return (NULL);
	list->fd = fd;
	list->line_buff = NULL;
	list->temp = NULL;
	if (!(list->fd_buff = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	list->next = NULL;
	if (*head)
		list->next = *head;
	*head = list;
	return (list);
}

int					get_next_line(const int fd, char **line)
{
	t_gnl			*data;
	static t_gnl	*head;
	int				r_buff;
	int				r_ost;

	r_ost = 1;
	if (fd < 0 || !(data = lst_new(fd, &head))
	|| !line || (read(fd, data->fd_buff, 0)) < 0)
		return (-1);
	if (data->temp)
	{
		if ((r_ost = ft_find(&data->temp, data)) == 0)
		{
			*line = data->line_buff;
			return (1);
		}
	}
	r_buff = ft_conct(data->fd_buff, data);
	*line = ft_strdup(data->line_buff);
	ft_strdel(&data->line_buff);
	if (r_buff == 0 && ft_strlen(*line) == 0)
	{
		while (data)
		{
			ft_strdel(&data->fd_buff);
			free(data);
			data = head->next;
		}
		return (0);
	}
	return (1);
}

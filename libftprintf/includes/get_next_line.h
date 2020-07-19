/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <lmonkfis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:23:25 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/11/20 22:09:59 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_GET_NEXT_LINE_H
# define GNL_GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 4

typedef	struct		s_gnl
{
	char			*temp;
	int				fd;
	char			*line_buff;
	char			*fd_buff;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
#endif

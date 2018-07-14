/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:15:05 by omiroshn          #+#    #+#             */
/*   Updated: 2018/07/14 21:15:07 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	create_2d_array(t_map *m, int x, int y)
{
	int i;

	i = -1;
	m->info.lines = (char **)malloc(sizeof(char *) * x);
	while (++i < x)
	{
		m->info.lines[i] = (char *)malloc(sizeof(char) * (y + 1));
	}
}

void		malloc_map(t_map *m)
{
	int		i;
	char	*line;
	char	**size;

	i = -1;
	while (get_next_line(0, &line) && !ft_strstr(line, "012345"))
	{
		if (ft_strstr(line, "p1"))
			m->info.user1 = ft_strsub(line, 14, ft_strlen(line));
		if (ft_strstr(line, "p2"))
			m->info.user2 = ft_strsub(line, 14, ft_strlen(line));
		if (ft_strstr(line, "Plateau"))
		{
			size = ft_strsplit(line, ' ');
			m->info.x = ft_atoi(size[1]);
			m->info.y = ft_atoi(size[2]);
			while (++i < 3)
				free(size[i]);
			free(size);
		}
		free(line);
	}
	free(line);
	create_2d_array(m, m->info.x, m->info.y);
}

void		read_user(t_map *m, char *line)
{
	if (ft_strstr(line, "p1"))
		m->info.user1 = ft_strsub(line, 14, ft_strlen(line));
	if (ft_strstr(line, "p2"))
		m->info.user2 = ft_strsub(line, 14, ft_strlen(line));
	ft_strdel(&line);
}

void		read_grid(t_map *m)
{
	char	*line;
	int		i;

	i = -1;
	while (get_next_line(0, &line) && !ft_strstr(line, "Piece"))
	{
		if (++i < m->info.x)
			ft_strcpy(m->info.lines[i], &line[4]);
		free(line);
	}
	free(line);
	while (get_next_line(0, &line) && !ft_strstr(line, "012345"))
		free(line);
	free(line);
}

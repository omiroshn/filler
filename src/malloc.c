/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:26:02 by omiroshn          #+#    #+#             */
/*   Updated: 2018/07/13 13:26:03 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	size_of_map(t_in *info, char *line)
{
	char **size;

	size = ft_strsplit(line, ' ');
	info->x = ft_atoi(size[1]);
	info->y = ft_atoi(size[2]);
}

void	size_of_token(t_in *info, char *line)
{
	char **size;

	size = ft_strsplit(line, ' ');
	info->xp = ft_atoi(size[1]);
	info->yp = ft_atoi(size[2]);
}

void	create_2d_array(t_in *info, int x, int y)
{
	int i;

	i = -1;
	info->lines = (char **)malloc(sizeof(char *) * x);
	info->nums = (int **)malloc(sizeof(int *) * x);
	while (++i < x)
	{
		info->lines[i] = (char *)malloc(sizeof(char) * (y + 1));
		info->nums[i] = (int *)malloc(sizeof(int) * y);
	}
}

void	create_2d_token_array(t_in *info, int x, int y)
{
	int		i;
	char	*line;

	i = -1;
	info->piece = (char **)malloc(sizeof(char *) * x);
	while (++i < x)
	{
		get_next_line(0, &line);
		info->piece[i] = ft_strdup(line);
	}
}

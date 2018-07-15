/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 18:38:19 by omiroshn          #+#    #+#             */
/*   Updated: 2018/06/29 18:38:20 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_player(t_in *info, char *line)
{
	if (ft_strstr(line, "$$$"))
	{
		if (ft_strstr(line, "p1"))
		{
			info->me = 'O';
			info->enemy = 'X';
		}
		else if (ft_strstr(line, "p2"))
		{
			info->me = 'X';
			info->enemy = 'O';
		}
	}
}

void	read_map(t_in *info)
{
	int		i;
	char	*line;

	i = -1;
	get_next_line(0, &line);
	while (get_next_line(0, &line) > 0
		&& !ft_strstr(line, "Piece"))
		if (++i < info->x)
			ft_strcpy(info->lines[i], &line[4]);
	size_of_token(info, line);
	create_2d_token_array(info, info->xp);
	manhattan(info);
	place_player(info);
}

int		main(void)
{
	t_in info;
	char *line;

	get_next_line(0, &line);
	read_player(&info, line);
	while (!ft_strstr(line, "Plateau"))
		get_next_line(0, &line);
	size_of_map(&info, line);
	create_2d_array(&info, info.x, info.y);
	read_map(&info);
	while (get_next_line(0, &line))
		read_map(&info);
	return (0);
}

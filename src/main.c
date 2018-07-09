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

void	size_of_map(t_in *info, char *line)
{
	char **size;

	size = ft_strsplit(line, ' ');
	info->x = ft_atoi(size[1]);
	info->y = ft_atoi(size[2]);
	get_next_line(0, &line);
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

void	shift_on_offset(t_in *info, FILE *f)
{
	int i;
	int j;

	i = -1;
	while (++i < info->xp && (j = -1))
		while (++j < info->yp)
			if ((info->piece[i][j] == '*' && info->minx)
				|| (info->piece[i][j] == '*' && info->miny))
			{
				info->piece[i - info->minx][j - info->miny] = '*';
				info->piece[i][j] = '.';
			}
	//printf
	for (int i = 0; i < info->xp; ++i)
		fprintf(f, "%s\n", info->piece[i]);
	fprintf(f, "\n");
}

void	offset_for_tokens(t_in *info, FILE *f)
{
	int offset_y;
	int offset_x;
	int i;
	int j;
	int star;
	
	i = -1;
	star = 0;
	offset_x = 0;
	info->minx = info->xp;
	info->miny = info->yp;
	while (++i < info->xp && (j = -1))
	{
		offset_y = 0;
		while (++j < info->yp)
		{
			if (info->piece[i][j] == '.')
				offset_y++;
			if (info->piece[i][j] == '*')
			{
				star = 1;
				break ;
			}
			if (offset_y == info->yp && !star)
				offset_x++;
		}
		if (offset_y < info->miny)
			info->miny = offset_y;
	}
	if (offset_x < info->minx)
		info->minx = offset_x;

	// printf
	fprintf(f, "\n%d %d\n\n", info->miny, info->minx);

	//sdvig na offset
	shift_on_offset(info, f);
}

int		manhattan_distance(t_in *info, int x, int y)
{
	int i;
	int j;
	int min;
	int len;

	len = 0;
	min = info->x + info->y;
	i = -1;
	while (++i < info->x && (j = -1))
		while (++j < info->y)
			if (info->nums[i][j] == ENEMY)
			{
				len = abs(i - x) + abs(j - y);
				if (len < min)
					min = len;
			}
	return (min);
}

void	manhattan(t_in *info, FILE *f)
{
	int i;
	int j;

	i = -1;
	while (++i < info->x && (j = -1))
		while (++j < info->y)
			if (info->lines[i][j] == '.')
				info->nums[i][j] = 0;
			else if (info->lines[i][j] == info->me
				|| info->lines[i][j] == info->me + 32)
				info->nums[i][j] = PLAYER;
			else if (info->lines[i][j] == info->enemy
				|| info->lines[i][j] == info->enemy + 32)
				info->nums[i][j] = ENEMY;
	i = -1;
	while (++i < info->x && (j = -1))
		while (++j < info->y)
			if (info->lines[i][j] == '.')
				info->nums[i][j] = manhattan_distance(info, i, j);

	//printf
	fprintf(f, "\n");
	for (int i = 0; i < info->x; ++i)
	{
		for (int j = 0; j < info->y; ++j)
			if (ft_intlen(info->nums[i][j]) == 2)
				fprintf(f, "%d ", info->nums[i][j]);
			else
				fprintf(f, "%d  ", info->nums[i][j]);
		fprintf(f, "\n");
	}
}

void	place_player(t_in *info, FILE *f)
{
	int i;
	int j;
	int sell;
	int sum;
	int manhattan;

	int xx = 0;
	int yy = 0;

	i = -1;
	sum = 0;
	sell = 0;
	manhattan = info->x + info->y;
	while (++i < info->x && (j = -1))
	{
		while (++j < info->y)
		{
			for (int ii = 0; ii < info->xp; ++ii)
			{
				for (int jj = 0; jj < info->yp; ++jj)
				{
					if (info->piece[ii][jj] == '*')
					{
						if (info->nums[i][j] == PLAYER)
							sell++;
						// if (info->nums[i][j] != PLAYER || info->nums[i][j] != ENEMY)
							sum += info->nums[i][j];
					}
				}
			}
			if (sell == 1 && sum < manhattan)
			{
				xx = i;
				yy = j;
				manhattan = sum;
			}
		}
	}
	fprintf(f, "SUM: %d\n", manhattan);
	fprintf(f, "POS: %d %d\n", xx, yy);
	// int manhatten = 999999;
	// int c, z;
	
	// int xx = 0;
	// int yy = 0;
	// for (int posX = 0; posX < x - xPeace; ++posX)
	// {
	// 	for (int posY = 0; posY < y - yPeace; ++posY)
	// 	{
	// 		c = 0;
	// 		sum = 0;
	// 		sell = 0;
	// 		for (int s = posX; s < posX + xPeace; ++s)
	// 		{
	// 			z = 0;
	// 			for (int d = posY; d < posY + yPeace; ++d)
	// 			{
	// 				if (piece[c][z] == '*')
	// 				{
	// 					if (nums[s][d] == 1 || nums[s][d] == 9)
	// 						sell++;
	// 					sum += chess[s][d];
	// 				}
	// 				z++;
	// 			}
	// 			c++;
	// 		}
	// 		if (sell == 1 && sum < manhatten)
	// 		{
	// 			xx = posX;
	// 			yy = posY;
	// 			manhatten = sum;
	// 		}
	// 	}
	// }
	// fprintf(f, "SUM: %d\n", manhatten);

	// c = 0;
	// for (int i = xx; i < xx + xPeace; ++i)
	// {
	// 	z = 0;
	// 	for (int j = yy; j < yy + yPeace; ++j)
	// 	{
	// 		if (piece[c][z] == '*')
	// 		{
	// 			nums[i][j] = 1;
	// 		}
	// 		else
	// 			nums[i][j] = 0;
	// 		z++;
	// 	}
	// 	c++;
	// }
}

void	read_map(t_in *info, FILE *f)
{
	int		i;
	char	*line;
	
	i = -1;
	while (get_next_line(0, &line) > 0 && !ft_strstr(line, "Piece"))
	{
		if (++i < info->x)
			info->lines[i] = &line[4];
	}
	//printf
	for (int i = 0; i < info->x; ++i)
	{
		fprintf(f, "%s\n", info->lines[i]);
	}
	size_of_token(info, line);
	create_2d_token_array(info, info->xp, info->yp);

	//printf
	for (int i = 0; i < info->xp; ++i)
	{
		fprintf(f, "%s\n", info->piece[i]);
	}
	//offset for tokens
	offset_for_tokens(info, f);
	manhattan(info, f);
	//postavit enemy & playera
	place_player(info, f);
}

int main(void)
{
	t_in		info;
	char		*line;

	//open file
	FILE *f = fopen("file.txt", "w");
	if (f == NULL) {
		system("touch file.txt");
	}

	// player
	get_next_line(0, &line);
	read_player(&info, line);
	while (!ft_strstr(line, "Plateau"))
		get_next_line(0, &line);

	//sizeofmap
	size_of_map(&info, line);
	create_2d_array(&info, info.x, info.y);

	//reading file
	read_map(&info, f);

	// fprintf(f, "\n");
	// for (int i = 0; i < x; ++i)
	// {
	// 	for (int j = 0; j < y; ++j)
	// 	{
	// 		fprintf(f, "%d", nums[i][j]);
	// 	}
	// 	fprintf(f, "\n");
	// }
	// fprintf(f, "%d %d %d %d %d %d\n", xx - minX, yy - minY, xx, minX, yy, minY);
	// ft_printf("%d %d\n", xx - minX, yy - minY);

		// // while (get_next_line(0, &line)) {
		// // 	fprintf(f, "%s\n", line);
		// // }
		// get_next_line(0, &line);
		// fprintf(f, "%s\n", line);
		// get_next_line(0, &line);
		// fprintf(f, "%s\n", line);
		// get_next_line(0, &line);
		// fprintf(f, "%s\n", line);
		// get_next_line(0, &line);
		// write(1, "8 0\n", 4);
		// write(1, "9 1\n", 4);
	// }
	return (0);
}

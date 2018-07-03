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

int main(int argc, char **argv)
{
	char		*line;
	int			player = 0;

	//file
	FILE *f = fopen("file.txt", "w");
	if (f == NULL) {
		system("touch file.txt");
	}

	//player
	get_next_line(0, &line);
	// fprintf(f, "%s\n", line);
	if (!ft_strncmp(line, "$$$", 3) && player == 0) {
		if (ft_strstr(line, "p1")) {
			player = 1;
		}
		else if (ft_strstr(line, "p2")) {
			player = 2;
		}
	}
	// free(line);
	// fprintf(f, "PLAYER: %d\n", player);

	//sizeofmap
	get_next_line(0, &line);
	// fprintf(f, "%s\n", line);
	char **size;
	size = ft_strsplit(line, ' ');
	int x = ft_atoi(size[1]);
	int y = ft_atoi(size[2]);
	free(size);
	// fprintf(f, "x: %d\n", x);
	// fprintf(f, "y: %d\n", y);
	free(line);
	get_next_line(0, &line);
	ft_strdel(&line);
	//reading file
	int i = 0;
	char **lines;
	char **piece;
	int xPeace = 0;
	int yPeace = 0;
	lines = (char **)malloc(sizeof(char *) * (x + 1));
	while (get_next_line(0, &line) > 0 && ft_strncmp(line, "Piece", 4)) {
		if (i < x) {
			lines[i] = ft_strdup((const char *)(&line[4]));
			i++;
			// fprintf(f, "%s\n", lines[i]);
		}
		// fprintf(f, "%s\n", line);
		free(line);
	}
	if (!ft_strncmp(line, "Piece", 4)) {
		size = ft_strsplit(line, ' ');
		xPeace = ft_atoi(size[1]);
		yPeace = ft_atoi(size[2]);
		piece = (char **)malloc(sizeof(char *) * (xPeace + 1));
		for (int i = 0; i < xPeace; ++i)
		{
			get_next_line(0, &line);
			piece[i] = ft_strdup((const char *)(line));
		}
	}

	for (int i = 0; i < x; ++i)
	{
		fprintf(f, "%s\n", lines[i]);
	}
	for (int i = 0; i < xPeace; ++i)
	{
		fprintf(f, "%s\n", piece[i]);
	}
	// printf("%d %d\n", 7, 2);

	int **nums;
	nums = (int **)malloc(sizeof(int *) * x);
	for (int i = 0; i < x; ++i) {
		nums[i] = (int *)malloc(sizeof(int) * y);
		for (int j = 0; j < y; ++j) {
			if (lines[i][j] == '.') {
				nums[i][j] = 0;
			} else if (lines[i][j] == 'O' || lines[i][j] == 'o') {
				nums[i][j] = 9;
			} else if (lines[i][j] == 'X' || lines[i][j] == 'x') {
				nums[i][j] = 8;
			}
		}
	}

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			fprintf(f, "%d", nums[i][j]);
		}
		fprintf(f, "\n");
	}
	return (0);
}

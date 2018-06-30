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
	fprintf(f, "%s\n", line);
	if (!ft_strncmp(line, "$$$", 3) && player == 0) {
		if (ft_strstr(line, "p1")) {
			player = 1;
		}
		else if (ft_strstr(line, "p2")) {
			player = 2;
		}
	}
	free(line);
	fprintf(f, "PLAYER: %d\n", player);
	
	//sizeofmap
	get_next_line(0, &line);
	fprintf(f, "%s\n", line);
	char **size;
	size = ft_strsplit(line, ' ');
	int x = ft_atoi(size[1]);
	int y = ft_atoi(size[2]);
	fprintf(f, "x: %d\n", x);
	fprintf(f, "y: %d\n", y);
	free(line);

	//reading file
	while (get_next_line(0, &line) > 0) {
		fprintf(f, "%s\n", line);
		free(line);
	}
	return (0);
}

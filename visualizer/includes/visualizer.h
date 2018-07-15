/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:53:50 by omiroshn          #+#    #+#             */
/*   Updated: 2018/07/13 15:53:52 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include <time.h>
# include <fcntl.h>
# include <SDL2/SDL.h>
# include "libft.h"
# include "ft_printf.h"

# ifdef __APPLE__
#  include "SDL_image.h"
#  include "SDL_mixer.h"
#  include "SDL_ttf.h"
# elif __linux__
#  include <SDL2/SDL_image.h>
#  include <SDL2/SDL_mixer.h>
#  include <SDL2/SDL_ttf.h>
# endif

# define FONTS_FOLDER "/fonts/"
# define WIDTH 1280
# define HEIGHT 1000
# define TRUE 1

typedef struct		s_in
{
	int		x;
	int		y;
	char	*user1;
	char	*user2;
	char	**lines;
	int		me;
	int		enemy;
	int		total;
}					t_in;

typedef struct		s_color
{
	int r;
	int g;
	int b;
}					t_color;

typedef	struct		s_map
{
	SDL_Window	*window;
	SDL_Surface	*screen;
	SDL_Surface *text;
	SDL_Surface *pause_surface;
	TTF_Font	*ttf;
	TTF_Font	*pause_ttf;
	t_in		info;
	t_color		color;
	float		offset;
	float		radius;
	int			mouse_pressed;
}					t_map;

void				draw_pause(t_map *m);
void				draw_grid(t_map *m);
void				draw_userinfo(t_map *m);
void				draw_score(t_map *m);
void				draw_procent_bar(t_map *m);
void				malloc_map(t_map *m);
void				read_user(t_map *m, char *line);
void				read_grid(t_map *m);
void				count_pieces(t_map *m, int i, int j);
void				put_error(const char *msg);
int					key_function(t_map *map);
int					quit(t_map *m);

#endif

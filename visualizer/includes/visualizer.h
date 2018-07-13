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

#ifdef __APPLE__
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
#elif __linux__
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_ttf.h>
#endif

# define FONTS_FOLDER "/fonts/"
# define WIDTH 1280
# define HEIGHT 1000
# define TRUE 1

typedef unsigned int	t_uint;

typedef struct	s_in
{
	int		x;
	int		y;
	int		xp;
	int		yp;
	int		minx;
	int		miny;
	int		xx;
	int		yy;
	char	me;
	char	enemy;
	char	*user1;
	char	*user2;
	char	**lines;
	char	**piece;
	int		**nums;
}				t_in;

typedef	struct	s_map
{
	SDL_Surface	*screen;
	SDL_Surface *text;
	SDL_Surface *fps;
	SDL_Window	*window;
	TTF_Font	*ttf;
	t_uint		*image;
	t_in		info;
}				t_map;

#endif

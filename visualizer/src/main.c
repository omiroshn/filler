/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:53:12 by omiroshn          #+#    #+#             */
/*   Updated: 2018/07/13 15:53:13 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	init(t_map *m)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		put_error(SDL_GetError());
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0)
		put_error(SDL_GetError());
	if (TTF_Init() < 0)
		put_error(SDL_GetError());
	if (!(m->ttf = TTF_OpenFont(FONTS_FOLDER"bad-mofo.regular.ttf", 38)))
		put_error(IMG_GetError());
	if (!(m->pause_ttf = TTF_OpenFont(FONTS_FOLDER"bad-mofo.regular.ttf", 100)))
		put_error(IMG_GetError());
	if (!(m->window = SDL_CreateWindow("Visualizer",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI)))
		put_error(SDL_GetError());
	m->screen = SDL_GetWindowSurface(m->window);
	m->info.user1 = NULL;
	m->info.user2 = NULL;
	m->mouse_pressed = 0;
}

int		main(void)
{
	t_map	m;

	init(&m);
	malloc_map(&m);
	while (TRUE)
	{
		if (!m.mouse_pressed)
		{
			ft_bzero(m.screen->pixels, m.screen->w * m.screen->h * 4);
			read_grid(&m);
			draw_grid(&m);
			draw_userinfo(&m);
			draw_score(&m);
			draw_procent_bar(&m);
		}
		else
			draw_pause(&m);
		if (!key_function(&m))
			break ;
		SDL_UpdateWindowSurface(m.window);
	}
	return (quit(&m));
}

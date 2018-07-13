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

int		quit(t_map *m)
{
	SDL_DestroyWindow(m->window);
	TTF_CloseFont(m->ttf);
	IMG_Quit();
	SDL_Quit();
	return (0);
}

void	put_error(const char *msg)
{
	if (!msg)
		exit(-1);
	ft_putendl(ft_strjoin("Error: ", msg));
	exit(-1);
}

int		key_function(t_map *map)
{
	SDL_Event	e;

	while (SDL_PollEvent(&e))
	{
		if ((e.type == SDL_QUIT) || (e.type == SDL_KEYDOWN
						&& e.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
			return (0);
	}
	return (1);
}

void	lsync(void)
{
	int					delay;
	static unsigned int	time;
	static char			vsync = 1;

	vsync == 1 ? SDL_GL_SetSwapInterval(1) : 0;
	if (vsync)
	{
		delay = 16 - (SDL_GetTicks() - time);
		if (delay < 0)
			SDL_Delay(0);
		else
			SDL_Delay(delay);
		time = SDL_GetTicks();
	}
}

void	display_fps(t_map *m)
{
	static t_uint	fps;
	static t_uint	time_current;
	static t_uint	time_past;
	static t_uint	ticks;
	char			*fps_str;

	time_current = time(NULL);
	if (time_current - time_past && (time_past = time_current))
		fps = 1000 / (SDL_GetTicks() - ticks);
	ticks = SDL_GetTicks();
	fps_str = ft_itoa(fps);
	m->fps = TTF_RenderText_Solid(m->ttf, fps_str,
					(SDL_Color){255, 255, 255, 255});
	SDL_BlitSurface(m->fps, NULL, m->screen,
		&(SDL_Rect){ m->screen->w / 2 - m->fps->w / 2,
					m->screen->h / 2 - m->fps->h / 2 + m->fps->h,
					m->fps->w,
					m->fps->h});
	SDL_FreeSurface(m->fps);
	ft_memdel((void**)&fps_str);
}

void	draw_rect(t_map *m, int x, int y)
{
	SDL_FillRect(m->screen,
			&(SDL_Rect){ (m->screen->w - x) / 2, (m->screen->h - y) / 2, x, y },
			SDL_MapRGB(m->screen->format, 255, 255, 0));
}

void	init(t_map *m)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		put_error(SDL_GetError());
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0)
		put_error(SDL_GetError());
	if (TTF_Init() < 0)
		put_error(SDL_GetError());
	if (!(m->ttf = TTF_OpenFont(FONTS_FOLDER"bad-mofo.regular.ttf", 30)))
		put_error(IMG_GetError());
	//alba.super.ttf / 2
	//bad-mofo.regular.ttf / 3 points
	//pricedown.black.ttf / 1
	if (!(m->window = SDL_CreateWindow("Visualizer",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI)))
		put_error(SDL_GetError());
	m->screen = SDL_GetWindowSurface(m->window);
	m->image = m->screen->pixels;
	m->info.user1 = NULL;
	m->info.user2 = NULL;
}

void	read_user(t_map *m, char *line)
{
	if (ft_strstr(line, "p1"))
		m->info.user1 = ft_strsub(line, 14, ft_strlen(line));
	if (ft_strstr(line, "p2"))
		m->info.user2 = ft_strsub(line, 14, ft_strlen(line));
	ft_strdel(&line);
}

int main(void)
{
	t_map	m;
	char	*line;

	init(&m);
	while (TRUE)
	{
		ft_bzero(m.screen->pixels, m.screen->w * m.screen->h * 4);
		display_fps(&m);
		if (get_next_line(0, &line))
		{
			if (ft_strstr(line, "$$$"))
				read_user(&m, line);
				// dprintf(2, "%s\n", line);
			// else if (ft_strstr(line, "Plateau"))

			// else if (ft_strstr(line, "Piece"))
			draw_rect(&m, 50, 50);
			m.text = TTF_RenderText_Solid(m.ttf, line, (SDL_Color){255, 255, 255, 255});
			SDL_BlitSurface(m.text, NULL, m.screen,
				&(SDL_Rect){ m.screen->w / 2 - m.text->w / 2,
					m.screen->h / 2 - m.text->h / 2,
					m.text->w,
					m.text->h});
		}
		if (m.info.user1)
		{
			m.text = TTF_RenderText_Solid(m.ttf, m.info.user1, (SDL_Color){68,53,91,255});
			SDL_BlitSurface(m.text, NULL, m.screen,
				&(SDL_Rect){ 10,
					10,
					m.text->w,
					m.text->h});
		}
		if (m.info.user2)
		{
			m.text = TTF_RenderText_Solid(m.ttf, m.info.user2, (SDL_Color){241,211,2, 255});
			SDL_BlitSurface(m.text, NULL, m.screen,
				&(SDL_Rect){ 10,
					30,
					m.text->w,
					m.text->h});
		}
		SDL_UpdateWindowSurface(m.window);
		if (!key_function(&m))
			break ;
	}
	return (quit(&m));
}
//COLORS FOR MAP:
//rgb(68,53,91) //purple1
//rgb(49,38,62) //purple2
//rgb(34,30,34) //font
//rgb(241,211,2) //yellow
//rgb(238,86,34) //orange
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:13:20 by omiroshn          #+#    #+#             */
/*   Updated: 2018/07/14 21:13:21 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	draw_rect(t_map *m, int x, int y, int radius)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		SDL_FillRect(m->screen,
				&(SDL_Rect){ x, y, radius, radius },
				SDL_MapRGB(m->screen->format,
					m->color.r, m->color.g, m->color.b));
}

static void	return_color(t_map *m, int i, int j)
{
	if (m->info.lines[i][j] == '.')
	{
		m->color.r = 34;
		m->color.g = 30;
		m->color.b = 34;
	}
	if (m->info.lines[i][j] == 'O' || m->info.lines[i][j] == 'o')
	{
		m->color.r = 68;
		m->color.g = 53;
		m->color.b = 91;
	}
	if (m->info.lines[i][j] == 'X' || m->info.lines[i][j] == 'x')
	{
		m->color.r = 241;
		m->color.g = 211;
		m->color.b = 2;
	}
}

void		draw_grid(t_map *m)
{
	int i;
	int j;
	int x;
	int y;

	i = -1;
	y = 70;
	if (m->info.x > m->info.y)
		m->offset = (HEIGHT - y) / m->info.x;
	else
		m->offset = (HEIGHT - y) / m->info.y;
	m->radius = (m->offset * 80) / 100;
	while (++i < m->info.x && (j = -1))
	{
		x = (WIDTH - (m->info.y * m->offset)) / 2;
		while (++j < m->info.y)
		{
			return_color(m, i, j);
			draw_rect(m, x, y, (int)m->radius);
			x += (int)m->offset;
		}
		y += (int)m->offset;
	}
}

void		draw_userinfo(t_map *m)
{
	if (m->info.user1)
	{
		m->text = TTF_RenderText_Solid(m->ttf, m->info.user1,
			(SDL_Color){ 68, 53, 91, 255 });
		SDL_BlitSurface(m->text, NULL, m->screen,
			&(SDL_Rect){10, 10, m->text->w + 10, m->text->h + 10});
		SDL_FreeSurface(m->text);
	}
	if (m->info.user2)
	{
		m->text = TTF_RenderText_Solid(m->ttf, m->info.user2,
			(SDL_Color){ 241, 211, 2, 255 });
		SDL_BlitSurface(m->text, NULL, m->screen, &(SDL_Rect){
			m->screen->w - m->text->w - 10, 10, m->text->w, m->text->h});
		SDL_FreeSurface(m->text);
	}
	m->text = TTF_RenderText_Solid(m->ttf, "VERSUS",
		(SDL_Color){ 238, 86, 34, 255 });
	SDL_BlitSurface(m->text, NULL, m->screen, &(SDL_Rect){
		(m->screen->w - m->text->w) / 2, 10, m->text->w, m->text->h});
	SDL_FreeSurface(m->text);
}

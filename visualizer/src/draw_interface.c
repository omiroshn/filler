/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 18:09:39 by omiroshn          #+#    #+#             */
/*   Updated: 2018/07/15 18:09:40 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		draw_procent_bar(t_map *m)
{
	float persent;
	float p_enemy;

	persent = ((m->info.me * 100) / m->info.total) * 4;
	p_enemy = ((m->info.enemy * 100) / m->info.total) * 4;
	SDL_FillRect(m->screen, &(SDL_Rect){ 50, 200, 50, 400 },
		SDL_MapRGB(m->screen->format, 120, 94, 161));
	SDL_FillRect(m->screen, &(SDL_Rect){ 50, 200, 50, 400 - (int)persent },
		SDL_MapRGB(m->screen->format, 68, 53, 91));
	SDL_FillRect(m->screen, &(SDL_Rect){ m->screen->w - 100, 200, 50, 400 },
		SDL_MapRGB(m->screen->format, 241, 211, 2));
	SDL_FillRect(m->screen, &(SDL_Rect){ m->screen->w - 100, 200,
		50, 400 - (int)p_enemy },
		SDL_MapRGB(m->screen->format, 173, 152, 1));
}

void		draw_score(t_map *m)
{
	char	*str;

	str = ft_itoa(m->info.me);
	m->text = TTF_RenderText_Solid(m->ttf, str,
		(SDL_Color){ 120, 94, 161, 255 });
	SDL_BlitSurface(m->text, NULL, m->screen,
		&(SDL_Rect){510, 10, m->text->w, m->text->h});
	SDL_FreeSurface(m->text);
	free(str);
	str = ft_itoa(m->info.enemy);
	m->text = TTF_RenderText_Solid(m->ttf, str,
		(SDL_Color){ 241, 211, 2, 255 });
	SDL_BlitSurface(m->text, NULL, m->screen,
		&(SDL_Rect){710, 10, m->text->w, m->text->h});
	SDL_FreeSurface(m->text);
	free(str);
}

void		draw_userinfo(t_map *m)
{
	if (m->info.user1)
	{
		m->text = TTF_RenderText_Solid(m->ttf, m->info.user1,
			(SDL_Color){ 68, 53, 91, 255 });
		SDL_BlitSurface(m->text, NULL, m->screen,
			&(SDL_Rect){10, 10, m->text->w, m->text->h});
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

void		draw_pause(t_map *m)
{
	m->pause_surface = TTF_RenderText_Solid(m->pause_ttf, "PAUSE",
			(SDL_Color){ 238, 86, 34, 255 });
	SDL_BlitSurface(m->pause_surface, NULL, m->screen,
			&(SDL_Rect){(m->screen->w - m->pause_surface->w) / 2,
			(m->screen->h - m->pause_surface->h) / 2,
			m->pause_surface->w, m->pause_surface->h});
	SDL_FreeSurface(m->pause_surface);
}

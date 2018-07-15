/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
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
		m->color = (t_color){ 34, 30, 34 };
	if (m->info.lines[i][j] == 'O')
		m->color = (t_color){ 68, 53, 91 };
	if (m->info.lines[i][j] == 'o')
		m->color = (t_color){ 120, 94, 161 };
	if (m->info.lines[i][j] == 'X')
		m->color = (t_color){ 173, 152, 1 };
	if (m->info.lines[i][j] == 'x')
		m->color = (t_color){ 241, 211, 2 };
}

void		draw_grid(t_map *m)
{
	int i;
	int j;
	int x;
	int y;

	y = 70;
	m->info.me = 0;
	m->info.enemy = 0;
	if ((i = -1) && m->info.x > m->info.y)
		m->offset = (HEIGHT - y) / m->info.x;
	else
		m->offset = (HEIGHT - y) / m->info.y;
	m->radius = (m->offset * 80) / 100;
	while (++i < m->info.x && (j = -1))
	{
		x = (WIDTH - (m->info.y * m->offset)) / 2;
		while (++j < m->info.y)
		{
			count_pieces(m, i, j);
			return_color(m, i, j);
			draw_rect(m, x, y, (int)m->radius);
			x += (int)m->offset;
		}
		y += (int)m->offset;
	}
}

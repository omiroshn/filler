/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:18:29 by omiroshn          #+#    #+#             */
/*   Updated: 2018/07/14 21:18:29 by omiroshn         ###   ########.fr       */
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

int		key_function(t_map *m)
{
	SDL_Event	e;

	while (SDL_PollEvent(&e))
	{
		if ((e.type == SDL_QUIT) || (e.type == SDL_KEYDOWN
			&& e.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
			return (0);
		if (e.type == SDL_MOUSEBUTTONDOWN)
			m->mouse_pressed ^= 1;
	}
	return (1);
}

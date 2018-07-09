/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 18:40:30 by omiroshn          #+#    #+#             */
/*   Updated: 2018/06/29 18:40:31 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

# define PLAYER -1
# define ENEMY -2

typedef struct  s_in
{
    int     x;
    int     y;
    int     xp;
    int     yp;
    int     minx;
    int     miny;
    char    me;
    char    enemy;
    char    **lines;
	char    **piece;
    int     **nums;
}               t_in;

#endif

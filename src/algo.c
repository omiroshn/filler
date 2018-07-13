/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:27:14 by omiroshn          #+#    #+#             */
/*   Updated: 2018/07/13 13:27:14 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		manhattan_distance(t_in *info, int x, int y)
{
	int i;
	int j;
	int min;
	int len;

	len = 0;
	min = info->x * info->y;
	i = -1;
	while (++i < info->x && (j = -1))
		while (++j < info->y)
			if (info->nums[i][j] == ENEMY)
			{
				len = abs(i - x) + abs(j - y);
				if (len < min)
					min = len;
			}
	return (min);
}

void			manhattan(t_in *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->x && (j = -1))
		while (++j < info->y)
			if (info->lines[i][j] == '.')
				info->nums[i][j] = 0;
			else if (info->lines[i][j] == info->me
				|| info->lines[i][j] == info->me + 32)
				info->nums[i][j] = PLAYER;
			else if (info->lines[i][j] == info->enemy
				|| info->lines[i][j] == info->enemy + 32)
				info->nums[i][j] = ENEMY;
	i = -1;
	while (++i < info->x && (j = -1))
		while (++j < info->y)
			if (info->lines[i][j] == '.')
				info->nums[i][j] = manhattan_distance(info, i, j);
}

static int		count(t_in *info, int i, int j, int sum)
{
	int ii;
	int jj;
	int sell;
	int enemy;

	sell = 0;
	enemy = 0;
	ii = -1;
	while (++ii < info->xp && (jj = -1))
		while (++jj < info->yp)
			if (info->piece[ii][jj] == '*')
			{
				if ((ii + i) < 0 || (ii + i) >= info->x
					|| (jj + j) < 0 || (jj + j) >= info->y)
					return (0);
				if (info->nums[ii + i][jj + j] == PLAYER)
					sell++;
				if (info->nums[ii + i][jj + j] == ENEMY)
					enemy++;
				sum += info->nums[ii + i][jj + j];
			}
	if (enemy || sell != 1)
		return (0);
	return (sum);
}

void			place_player(t_in *info)
{
	int i;
	int j;
	int sum;
	int manhattan;

	manhattan = info->x * info->y;
	i = -info->xp;
	while (++i < info->x + info->xp && (j = -info->yp))
		while (++j < info->y + info->yp)
		{
			sum = 0;
			sum = count(info, i, j, sum);
			if (sum != 0 && sum < manhattan)
			{
				info->xx = i;
				info->yy = j;
				manhattan = sum;
			}
		}
	ft_printf("%d %d\n", info->xx, info->yy);
}

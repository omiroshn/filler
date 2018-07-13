/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_else.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:51:19 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/12 20:51:20 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static void	print(t_info *info, t_num n, const char *str, int i)
{
	if (!info->space)
	{
		write(1, &str[i], 1);
		info->res++;
	}
	if (info->minus)
		while (n.wid-- > 0)
			write(1, " ", 1);
}

int					print_else(t_info *info, t_num n, const char *str, int i)
{
	if (info->star && info->width < 0)
	{
		info->minus = 1;
		info->width = -info->width;
	}
	if (info->width > 0)
	{
		info->width -= 1;
		info->res += info->width;
	}
	n.wid = info->width;
	if (!info->minus && !info->zero && info->width > 0)
		while (info->width-- > 0)
			write(1, " ", 1);
	if (!info->minus && info->zero && info->precision <= 0)
		while (info->width-- > 0)
			write(1, "0", 1);
	else if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	print(info, n, str, i);
	return (i);
}

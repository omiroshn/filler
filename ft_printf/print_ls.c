/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:50:56 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/12 20:50:57 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static void	print(t_info *info, t_num *n)
{
	if (!(n->swit = va_arg(info->valist, wint_t*)))
		n->swit = L"(null)";
	if (info->star && info->width < 0)
	{
		info->minus = 1;
		info->width = -info->width;
	}
	if (info->width > 0 && ft_ustrlen(n->swit) > info->precision)
	{
		if (info->precision >= 0 && info->dot)
			info->width -= ft_spreclen(n->swit, info->precision);
		else
			info->width -= ft_ustrlen(n->swit);
	}
	if (info->precision > 0 && ft_ustrlen(n->swit) < info->precision)
		info->width -= ft_ustrlen(n->swit);
	if (info->width > 0)
		info->res += info->width;
	n->wid = info->width;
}

int					print_ls(t_info *info, t_num n, int i)
{
	print(info, &n);
	if (!info->minus && !info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	if (!info->minus && info->zero && info->precision <= 0)
		while (info->width-- > 0)
			write(1, "0", 1);
	else if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	if (info->precision >= 0 &&
		ft_ustrlen(n.swit) > info->precision && info->dot)
		info->res += ft_putustrl(n.swit, info->precision);
	else
	{
		ft_putustr(n.swit);
		info->res += ft_ustrlen(n.swit);
	}
	if (info->minus)
		while (n.wid-- > 0)
			write(1, " ", 1);
	return (i);
}

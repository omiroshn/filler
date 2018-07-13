/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:50:33 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/12 20:50:34 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static void	print_aa(t_info *info, t_num *n, const char *str, int i)
{
	n->uimaxt = ft_cast_hex(n->uimaxt, info, str, i);
	n->s = ft_itoa_base(n->uimaxt, 8, 0);
	n->prec = info->precision;
	if (info->width > 0)
		info->width -= ft_strlen(n->s);
	if (info->hash && n->uimaxt != 0 && !info->precision)
	{
		info->width -= 1;
		info->res += 1;
	}
	if (info->width && n->uimaxt == 0 && n->prec == 0 && info->dot)
		info->width++;
	if (info->precision > 0)
	{
		info->precision -= ft_strlen(n->s);
		info->width = info->precision > 0 ?
			info->width - info->precision : info->width;
	}
	if (info->width > 0)
		info->res += info->width;
	if (info->precision > 0)
		info->res += info->precision;
	n->wid = info->width;
}

inline static void	print_bb(t_info *info, t_num *n)
{
	if (!info->minus && !info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	if ((!info->minus && info->zero && info->precision <= 0) ||
		(!info->minus && info->dot && info->precision))
	{
		if (info->hash && n->uimaxt != 0 && !info->dot)
			ft_putstr("0");
		while (info->width-- > 0)
			write(1, "0", 1);
	}
	else if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	if ((info->hash && n->uimaxt != 0 && !info->zero && info->precision == 0)
		|| (info->hash && n->uimaxt != 0
			&& info->minus && info->precision == 0))
	{
		n->s2 = n->s;
		n->s = ft_strjoin("0", n->s2);
		info->res -= 1;
		free(n->s2);
	}
	while (info->precision-- > 0)
		write(1, "0", 1);
}

int					print_o(t_info *info, t_num n, const char *str, int i)
{
	print_aa(info, &n, str, i);
	print_bb(info, &n);
	if (n.uimaxt == 0 && n.prec == 0 && info->dot && !info->hash)
		return (i);
	ft_putstr(n.s);
	info->res += ft_strlen(n.s);
	if (info->minus)
		while (n.wid-- > 0)
			write(1, " ", 1);
	free(n.s);
	return (i);
}

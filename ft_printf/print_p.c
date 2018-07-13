/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:50:52 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/12 20:50:53 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static void	print(t_info *info, t_num *n)
{
	n->uimaxt = va_arg(info->valist, uintmax_t);
	n->s = ft_itoa_base(n->uimaxt, 16, 0);
	if (info->width > 0)
		info->width -= ft_strlen(n->s) + 2;
	if (info->width && n->uimaxt == 0 && info->precision == 0 && info->dot)
		info->width++;
	if (info->precision > 0)
	{
		n->uimaxt != 0 ? info->precision -= ft_strlen(n->s) : 0;
		info->width = info->precision > 0 ?
			info->width - info->precision : info->width;
	}
	if (info->width > 0)
		info->res += info->width;
	if (info->precision > 0)
		info->res += info->precision;
	n->wid = info->width;
	if (!info->minus && !info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
}

int					print_p(t_info *info, t_num n, int i)
{
	print(info, &n);
	if (n.uimaxt == 0 && info->dot)
	{
		ft_putstr("0x");
		while (info->precision-- > 0)
			write(1, "0", 1);
		info->res += 2;
		return (i);
	}
	ft_putstr("0x");
	while (info->precision-- > 0)
		write(1, "0", 1);
	if (!info->minus && info->zero && info->precision <= 0)
		while (info->width-- > 0)
			write(1, "0", 1);
	else if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	ft_putstr(n.s);
	info->res += ft_strlen(n.s) + 2;
	if (info->minus)
		while (n.wid-- > 0)
			write(1, " ", 1);
	free(n.s);
	return (i);
}

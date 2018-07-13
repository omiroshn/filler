/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:50:28 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/12 20:50:29 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static void	print(t_info *info, t_num *n, const char *str, int i)
{
	n->imaxt = ft_cast_hex(n->imaxt, info, str, i);
	n->prec = info->precision;
	if (info->width > 0)
		info->width -= ft_intlen_u(n->imaxt);
	if (info->width && n->imaxt == 0 && n->prec == 0 && info->dot)
		info->width++;
	if (info->precision > 0)
	{
		info->precision -= ft_intlen_u(n->imaxt);
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

int					print_u(t_info *info, t_num n, const char *str, int i)
{
	print(info, &n, str, i);
	if (!info->minus && info->zero && info->precision <= 0)
		while (info->width-- > 0)
			write(1, "0", 1);
	else if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	while (info->precision-- > 0)
		write(1, "0", 1);
	if (n.imaxt == 0 && n.prec == 0 && info->dot)
		return (i);
	n.s = ft_itoa_u(n.imaxt);
	ft_putstr(n.s);
	info->res += ft_intlen_u(n.imaxt);
	if (info->minus)
		while (n.wid-- > 0)
			write(1, " ", 1);
	free(n.s);
	return (i);
}

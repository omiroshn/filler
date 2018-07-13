/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:44:16 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/12 20:44:16 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static void	print_aa(t_info *info, t_num *n, const char *str, int i)
{
	n->imaxt = ft_cast_int(n->imaxt, info, str, i);
	n->prec = info->precision;
	if (info->star && info->width < 0)
	{
		info->minus = 1;
		info->width = -info->width;
	}
	if (info->width > 0)
		info->width -= ft_intlen(n->imaxt);
	if (info->width && n->imaxt == 0 && n->prec == 0 && info->dot)
		info->width++;
	if (info->precision > 0)
	{
		info->precision -= ft_intlen(n->imaxt);
		n->imaxt < 0 ? info->precision++ : 0;
		info->width = info->precision > 0 ?
			info->width - info->precision : info->width;
	}
	if ((n->imaxt >= 0 && info->plus)
		|| (n->imaxt >= 0 && info->space && info->zero && info->width > 0))
		info->width--;
}

inline static void	print_bb(t_info *info, t_num *n)
{
	if (info->width > 0)
		info->res += info->width;
	if (info->precision > 0)
		info->res += info->precision;
	n->wid = info->width;
	if ((n->imaxt >= 0 && info->space && !info->width)
		|| (n->imaxt >= 0 && info->space && info->zero && info->width > 0))
	{
		write(1, " ", 1);
		info->res++;
	}
	if (!info->minus && !info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	if (n->imaxt >= 0 && info->plus)
	{
		write(1, "+", 1);
		info->res++;
	}
}

inline static void	print_cc(t_info *info, t_num *n)
{
	if (!info->minus && info->zero && info->precision <= 0)
	{
		if (n->imaxt < 0)
		{
			write(1, "-", 1);
			n->imaxt *= -1;
			info->res++;
		}
		while (info->width-- > 0)
			write(1, "0", 1);
	}
	else if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	if (n->imaxt < 0 && (unsigned long)n->imaxt != -9223372036854775808U)
	{
		write(1, "-", 1);
		n->imaxt *= -1;
		info->res++;
	}
}

int					print_d(t_info *info, t_num n, const char *str, int i)
{
	print_aa(info, &n, str, i);
	print_bb(info, &n);
	print_cc(info, &n);
	while (info->precision-- > 0)
		write(1, "0", 1);
	if (n.imaxt == 0 && n.prec == 0 && info->dot)
		return (i);
	n.s = ft_itoa(n.imaxt);
	ft_putstr(n.s);
	info->res += ft_intlen(n.imaxt);
	if (info->minus)
		while (n.wid-- > 0)
			write(1, " ", 1);
	free(n.s);
	return (i);
}

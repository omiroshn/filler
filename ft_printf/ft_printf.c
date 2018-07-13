/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:39:22 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/30 18:23:40 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_info *info, t_num *n)
{
	info->hash = 0;
	info->minus = 0;
	info->plus = 0;
	info->zero = 0;
	info->space = 0;
	info->star = 0;
	info->width = 0;
	info->precision = 0;
	info->dot = 0;
	info->cast = 0;
	info->smt = 0;
	info->changed = 0;
	n->imaxt = 0;
	n->uimaxt = 0;
	n->swit = 0;
	n->cwit = 0;
	n->prec = 0;
	n->wid = 0;
	n->s = 0;
	n->s2 = 0;
}

int		deal_with_flags(t_info *info, const char *str, int i)
{
	while (!is_flag(str[i]))
	{
		info->changed = 0;
		i = parse_flags(info, str, i);
		if (info->changed)
			continue ;
		i = parse_width(info, str, i);
		if (info->changed)
			continue ;
		i = parse_length(info, str, i);
		if (info->changed)
			continue ;
		if (str[i] == '%')
			return (i);
		else if (someth_else(str[i]) && str[i - 1] != '%')
		{
			info->smt = 1;
			if (info->width || info->minus)
				return (i);
			return (--i);
		}
		else
			i++;
	}
	return (i);
}

int		deal_with_types(t_info *info, t_num n, const char *str, int i)
{
	if (str[i] == 'd' || str[i] == 'D' || str[i] == 'i')
		return (print_d(info, n, str, i));
	else if (str[i] == 'u' || str[i] == 'U')
		return (print_u(info, n, str, i));
	else if (str[i] == 'o')
		return (print_o(info, n, str, i));
	else if (str[i] == 'O')
		return (print_lo(info, n, str, i));
	else if (str[i] == 'x')
		return (print_x(info, n, str, i));
	else if (str[i] == 'X')
		return (print_lx(info, n, str, i));
	else if (str[i] == 'p')
		return (print_p(info, n, i));
	else if (str[i] == 'S' || (str[i] == 's' && info->cast == _LONG))
		return (print_ls(info, n, i));
	else if (str[i] == 's')
		return (print_s(info, n, i));
	else if (str[i] == 'c' || str[i] == 'C')
		return (print_c(info, n, str, i));
	else if (str[i] == '%')
		return (print_percent(info, n, i));
	else if (info->smt)
		return (print_else(info, n, str, i));
	return (i);
}

int		parse_argument(const char *str, t_info *info, t_num n)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (info->res);
			i++;
			init_flags(info, &n);
			i = deal_with_flags(info, str, i);
			i = deal_with_types(info, n, str, i);
		}
		else
		{
			write(1, &str[i], 1);
			info->res += 1;
		}
		i++;
	}
	return (info->res);
}

int		ft_printf(const char *msg, ...)
{
	t_info	info;
	t_num	n;

	info.res = 0;
	init_flags(&info, &n);
	va_start(info.valist, msg);
	info.res = parse_argument(msg, &info, n);
	va_end(info.valist);
	return (info.res);
}

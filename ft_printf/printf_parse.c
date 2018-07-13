/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:14:43 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/13 14:14:45 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flags(t_info *info, const char *str, int i)
{
	if (str[i] == '-' && i++ && (info->changed = 1))
		info->minus = 1;
	else if (str[i] == '+' && i++ && (info->changed = 1))
		info->plus = 1;
	else if (str[i] == ' ' && (info->changed = 1))
	{
		info->space = 1;
		if (str[i + 1] == ' ')
			while (str[i] == ' ')
				i++;
		else
			i++;
	}
	else if (str[i] == '#' && i++ && (info->changed = 1))
		info->hash = 1;
	else if (str[i] == '0' && i++ && (info->changed = 1))
		info->zero = 1;
	return (i);
}

int		parse_width(t_info *info, const char *str, int i)
{
	if (str[i] == '*' && i++ && (info->changed = 1))
	{
		info->star = 1;
		if (info->dot == 0)
			info->width = va_arg(info->valist, int);
		else if (info->dot == 1)
			info->precision = va_arg(info->valist, int);
	}
	else if (str[i] > '0' && str[i] <= '9' && (info->changed = 1))
	{
		info->width = count_stoi(&str[i]);
		i += count_width(&str[i]);
	}
	else if (str[i] == '.' && i++ && (info->changed = 1))
	{
		info->dot = 1;
		info->precision = count_stoi(&str[i]);
		i += count_width(&str[i]);
	}
	return (i);
}

int		parse_length(t_info *info, const char *str, int i)
{
	if (str[i] == 'l' && i++ && (info->changed = 1))
		info->cast = _LONG;
	else if (str[i] == 'h' && str[i + 1] == 'h'
		&& i++ && i++ && (info->changed = 1))
		info->cast = _UCHAR;
	else if (str[i] == 'h' && i++ && (info->changed = 1))
		info->cast = _USHORTINT;
	else if (str[i] == 'l' && str[i + 1] == 'l'
		&& i++ && i++ && (info->changed = 1))
		info->cast = _LONGLONG;
	else if (str[i] == 'j' && i++ && (info->changed = 1))
		info->cast = _UINTMAXT;
	else if (str[i] == 'z' && i++ && (info->changed = 1))
		info->cast = _SIZET;
	return (i);
}

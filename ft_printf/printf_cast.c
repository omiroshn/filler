/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:56:28 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/12 20:56:29 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_cast_hex(uintmax_t temp, t_info *info, const char *str, int i)
{
	if (info->cast == _LONG || str[i] == 'U' || str[i] == 'O')
		temp = va_arg(info->valist, unsigned long);
	else if (info->cast == _UCHAR)
		temp = (unsigned char)va_arg(info->valist, int);
	else if (info->cast == _USHORTINT)
		temp = (unsigned short)va_arg(info->valist, int);
	else if (info->cast == _LONGLONG)
		temp = va_arg(info->valist, unsigned long long);
	else if (info->cast == _UINTMAXT)
		temp = va_arg(info->valist, uintmax_t);
	else if (info->cast == _SIZET)
		temp = va_arg(info->valist, size_t);
	else
		temp = va_arg(info->valist, unsigned int);
	return (temp);
}

intmax_t	ft_cast_int(intmax_t temp, t_info *info, const char *str, int i)
{
	if (info->cast == _LONG || str[i] == 'D')
		temp = va_arg(info->valist, long);
	else if (info->cast == _UCHAR)
		temp = (signed char)va_arg(info->valist, int);
	else if (info->cast == _USHORTINT)
		temp = (short)va_arg(info->valist, int);
	else if (info->cast == _LONGLONG)
		temp = va_arg(info->valist, long long);
	else if (info->cast == _UINTMAXT)
		temp = va_arg(info->valist, intmax_t);
	else if (info->cast == _SIZET)
		temp = va_arg(info->valist, size_t);
	else
		temp = va_arg(info->valist, int);
	return (temp);
}

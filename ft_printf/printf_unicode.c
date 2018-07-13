/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:23:14 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/13 14:23:15 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putustrl(wint_t *s, int len)
{
	int i;
	int count;
	int ret;

	i = -1;
	count = 0;
	ret = 0;
	if (ft_ustrlen(s) < len)
	{
		while (*s)
			ft_putchar(*s++);
		return (len);
	}
	else
		while (++i < len)
		{
			count += ft_ucharlen(s[i]);
			if (count <= len)
			{
				ret += ft_ucharlen(s[i]);
				ft_putchar(s[i]);
			}
		}
	return (ret);
}

void	ft_putustr(wint_t *s)
{
	while (*s)
		ft_putchar(*s++);
}

int		ft_ustrlen(wchar_t *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
		len += ft_ucharlen(str[i++]);
	return (len);
}

int		ft_spreclen(wint_t *s, int len)
{
	int i;
	int count;
	int ret;

	count = 0;
	ret = 0;
	i = -1;
	while (++i < len)
	{
		count += ft_ucharlen(s[i]);
		if (count <= len)
			ret += ft_ucharlen(s[i]);
	}
	return (ret);
}

void	ft_putstrl(char *str, int len)
{
	int i;

	i = -1;
	while (++i < len)
		write(1, &str[i], 1);
}

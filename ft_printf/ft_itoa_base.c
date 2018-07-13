/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:42:18 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/30 18:42:20 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(uintmax_t num, int base)
{
	int count;

	count = 0;
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num = num / base;
		count++;
	}
	return (count);
}

static char	*ft_to_lower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

char		*ft_itoa_base(uintmax_t num, int base, int flag)
{
	int		length;
	char	*str;
	char	*abc;

	abc = "0123456789ABCDEF";
	length = ft_intlen(num, base);
	str = ft_strnew(length);
	if (str)
	{
		str[length] = '\0';
		if (num == 0)
			str[0] = '0';
		while (num != 0)
		{
			length--;
			str[length] = abc[num % base];
			num = num / base;
		}
		if (flag == 0)
			str = ft_to_lower(str);
	}
	return (str);
}

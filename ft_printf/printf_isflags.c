/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_isflags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:20:05 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/13 14:20:06 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		someth_else(char c)
{
	if (c != '-' || c != '+' || c != ' ' || c != '#' || c != '0'
		|| c != '*' || c != '.' || !(c > '0' && c <= '9'))
		return (1);
	return (0);
}

int		is_flag(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd'
		|| c == 'D' || c == 'i' || c == 'o' || c == 'O'
		|| c == 'u' || c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C')
		return (1);
	return (0);
}

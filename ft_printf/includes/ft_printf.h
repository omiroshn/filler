/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:26:20 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/30 18:13:29 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <stdint.h>
# include "libft.h"

# define _LONG 1
# define _UCHAR 2
# define _USHORTINT 3
# define _LONGLONG 4
# define _UINTMAXT 5
# define _SIZET 6

typedef struct		s_num
{
	intmax_t		imaxt;
	intmax_t		uimaxt;
	wint_t			*swit;
	wint_t			cwit;
	int				prec;
	int				wid;
	char			*s;
	char			*s2;
}					t_num;

typedef	struct		s_info
{
	va_list			valist;
	int				res;
	int				hash;
	int				minus;
	int				plus;
	int				zero;
	int				space;
	int				star;
	int				percent;
	int				width;
	int				precision;
	int				cast;
	int				dot;
	int				smt;
	int				changed;
}					t_info;

/*
**					ft_printf.c
*/

int					ft_printf(const char *msg, ...);

/*
**					printf_cast.c
*/

uintmax_t			ft_cast_hex(uintmax_t temp, t_info *info,
										const char *str, int i);
intmax_t			ft_cast_int(intmax_t temp, t_info *info,
										const char *str, int i);

/*
**					printf_isflags.c
*/

int					someth_else(char c);
int					is_flag(char c);

/*
**					printf_parse.c
*/

int					parse_flags(t_info *info, const char *str, int i);
int					parse_width(t_info *info, const char *str, int i);
int					parse_length(t_info *info, const char *str, int i);

/*
**					printf_unicode.c
*/

int					ft_putustrl(wint_t *s, int len);
void				ft_putustr(wint_t *s);
int					ft_ustrlen(wchar_t *str);
int					ft_spreclen(wint_t *s, int len);
void				ft_putstrl(char *str, int len);

/*
**					printf_countlength.c
*/

int					ft_intlen_u(uintmax_t num);
int					ft_intlen(intmax_t num);
int					ft_ucharlen(int c);
int					count_width(const char *str);
int					count_stoi(const char *str);

/*
**					printf_types
*/

int					print_d(t_info *info, t_num n, const char *str, int i);
int					print_u(t_info *info, t_num n, const char *str, int i);
int					print_o(t_info *info, t_num n, const char *str, int i);
int					print_lo(t_info *info, t_num n, const char *str, int i);
int					print_x(t_info *info, t_num n, const char *str, int i);
int					print_lx(t_info *info, t_num n, const char *str, int i);
int					print_p(t_info *info, t_num n, int i);
int					print_ls(t_info *info, t_num n, int i);
int					print_s(t_info *info, t_num n, int i);
int					print_c(t_info *info, t_num n, const char *str, int i);
int					print_percent(t_info *info, t_num n, int i);
int					print_else(t_info *info, t_num n, const char *str, int i);

/*
**					printf_itoa_u.c
*/

char				*ft_itoa_u(uintmax_t n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:45:09 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/24 13:15:27 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

# define LL		long long
# define ULL	unsigned long long
# define UL		unsigned long
# define UI		unsigned int
# define ILL	int long long
# define MASK8	"0xxxxxxx"
# define MASK16	"110xxxxx10xxxxxx"
# define MASK24	"1110xxxx10xxxxxx10xxxxxx"
# define MASK32	"11110xxx10xxxxxx10xxxxxx10xxxxxx"
# define VALID "# -+0987654321.hlzj"
# define FLAG_END "sSpdDioOuUxXcC%"
# define SSTR	fspec->str
# define SFLAG	fspec->flag
# define SMODIF	fspec->modifier
# define SINTMODIF fspec->int_modif
# define SPFX fspec->pfx
# define SLENPFX fspec->len_pfx
# define SMIN fspec->min_w
# define SMAX fspec->max_w
# define SARGT fspec->arg_type
# define SHTAG fspec->htag
# define SJUSTIFY fspec->justify
# define SDOT fspec->dot
# define SZERO fspec->zero
# define SPLUS fspec->plus
# define SSPACE fspec->space
# define SBASE fspec->base
# define SLEN fspec->len

typedef struct			s_fspec {
	char				*str;
	char				*flag;
	char				*modifier;
	char				*pfx;
	char				arg_type;
	size_t				len_pfx;
	size_t				min_w;
	size_t				max_w;
	int					int_modif;
	int					len;
	int					base;
	int					htag;
	int					justify;
	int					dot;
	int					zero;
	int					plus;
	int					space;
}						t_fspec;

int						ft_printf(const char *format, ...);
void					ft_parse_flag(t_fspec *fspec);
void					ft_handle_char(t_fspec *fspec, va_list ap);
void					ft_handle_int(t_fspec *fspec, va_list ap);
void					ft_handle_str(t_fspec *fspec, va_list ap);
void					ft_handle_uint(t_fspec *fspec, va_list ap);
void					ft_handle_ptr(t_fspec *fspec, va_list ap);
void					ft_handle_wchar(t_fspec *fspec, va_list ap);
void					ft_handle_wstr(t_fspec *fspec, va_list ap);
void					ft_handle_invalid(t_fspec *fspec);
char					*ft_putc_str(char c, char *dst, LL len);
char					*ft_justify(char *value, t_fspec *fspec);
char					*ft_llitoa(LL i, int base);
char					*ft_ullitoa(ULL i, ULL base);
void					ft_to_lower(char *str);
void					ft_free_fspec(t_fspec **fspec);
void					ft_mask(LL value, t_fspec *fspec);
size_t					ft_get_wstr_len(wchar_t *value);
int						ft_get_wchar_len(wchar_t c);
char					*ft_mask_wstr(LL value);
int						ft_bin_to_dec(char *str);
char					*ft_fill_mask(char *s1, char *s2);
void					ft_wstr_print(wchar_t *value);
char					*ft_add_pfx(char *test, t_fspec *fspec);
void					ft_get_pfx_and_base(t_fspec *fspec);
char					*ft_str_min(char *str, t_fspec *fspec);

#endif

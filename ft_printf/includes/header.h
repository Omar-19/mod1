/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:44:46 by btheia            #+#    #+#             */
/*   Updated: 2019/11/22 18:36:54 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdarg.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <stddef.h>
# include <float.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define MY_LONG_MIN (-0x7fffffffffffffffL-1)
# define RAZR (__uint128_t)10000000000000000000UL
# define RETF(x) (((*(uint32_t*)(&x) >> 23) & (uint32_t)0xFF)  - 127)
# define RETD(x) (((*(uint64_t *)(&d.numd) >> 52) & 0x7FF) - 1023)
# define RETLD(x) (((*(__uint128_t*)(&d.numld) >> 64) & 0x7FFF) - 16383)
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"
# define BUFF_SIZE 7

typedef union	u_double
{
	long double		numld;
	double			numd;
	float			numf;
}				t_double;

typedef struct	s_val
{
	char	type;
	char	length[2];
}				t_val;

typedef struct	s_intp
{
	unsigned long long	val[2];
	char				*str;
	int					size;
	int					flag;
}				t_intp;

typedef struct	s_param
{
	int		precision;
	int		is_pres;
	int		is_width;
	char	flags[5];
	int		is_minus;
	int		is_plus;
	int		is_zero;
	int		is_space;
	int		is_hash;
	int		width;
	int		len;
	int		result;
}				t_param;

void			ft_write_tail_percent(t_param *f_p_s);
void			ft_write_no_min_int(t_param *f_p_s, char *ptr, char *str[2]);
void			ft_write_min_int(t_param *f_p_s, char *ptr, char *str[2]);
void			ft_result_len_int(t_param *f_p_s);
void			ft_write_tail_int(t_param *f_p_s, char *ptr);
int				read_variable_percent(const char *str, size_t len,
	t_param *form_place_spc);
void			ft_result_len_char(t_param *f_p_s);
void			ft_write_tail_char(t_param *f_p_s, char c);
void			ft_write_tail_str(t_param *f_p_s, char *ptr);
void			ft_result_len_xo(t_param *f_p_s);
void			ft_xo_write_min(t_param *f_p_s, char *ptr,
	char ho, char *str[2]);
void			ft_xo_write(t_param *f_p_s, char *ptr, char ho, char *str[2]);
void			ft_write_tail_xo(t_param *f_p_s, char *ptr, char ho);
void			ft_flag_correction3(t_param *f_p_s);
void			ft_flag_correction2(t_param **f_p_s);
void			ft_string_processing1(t_param *f_p_s, int i[3],
	int flag, char *str);
void			ft_write1(t_param *f_p_s, char c, char *ptr);
void			ft_write2(t_param *f_p_s, char c, char *ptr, int i);
void			ft_write_min(char *str, int i, char *ptr, t_param *f_p_s);
void			ft_flag_correction_1(t_param *f_p_s);
void			ft_flag_correction(t_param *f_p_s);
void			ft_write_tail(t_param *f_p_s, char c, char *ptr);
char			hex_intc(char *s, int p);
char			*point_hex(void *a, int prs);
char			octa_intc(char *s);
char			*octa_int(void *a, int ltype);
char			*ft_strnew_char(int size, char c);
int				ft_only_space(char *str);
int				read_variable_float(const char *str, size_t len,
	va_list elem, t_param *form_place_spc);
char			*ft_ltoa_base(long long num, int base);
char			*ft_strnew(size_t size);
char			*arrayreverse(char *s);
char			*ft_uint64toa(uint64_t a, int d);
void			okrug(char **d, int t);
void			set_min(char **d, char c);
char			*ft_strnewc(size_t n, char c);
char			*set_p(char *s, int pos);
char			*main_c(char *s);
void			wr(uint64_t *res, int len, FILE *f);
void			wf(uint64_t *res, int len);
char			*cr_dc(char *s, size_t m1, int len, int i);
void			umn(uint64_t *tmp, int deg, int *min, int ndb);
int				min_i(int *a, int *b);
int				sum_m(uint64_t *res, uint64_t *tmp, int min, int ndb);
char			*drob(char *s, int t);
char			*drob1(char *s, size_t m1, int max_d);
char			*drob2(uint64_t *res, int t, int m1, int res_n, int max_d);
char			*del(uint64_t *tmp, int deg, int ndb, int t);
char			*del1_one(uint64_t *tmp, int deg, int ndb, int t);
char			*mastos(int *a, int t);
void			toone(uint64_t *tmp, int m1);
char			*cr_sdc(uint64_t *a, int min, size_t m1);
char			*hex_int(void *a, int p, int type);
char			*get_val(char *s);
char			*main_p(char **s, int pos);
char			*float_f(t_double d, int prs, int *sign);
char			*float_d(t_double d, int prs, int *sign);
char			*float_ld(t_double d, int prs, int *sign);
void			init_massiv(uint64_t *res, uint64_t *tmp, size_t m1);
void			umn1(uint64_t *tmp, int deg, int *min, int ndb);
int				okrug1(char **d, int t);
void			init_help_del1(__uint128_t *a, int *o, int deg);
int				search_non(uint64_t *tmp, int ndb);
void			ret_byties_float(t_double d, int *a, int type, char *l);
void			sum_mhelp(__uint128_t *s, int *i);
void			sum_mhelp2(__uint128_t *s, __uint128_t f,
	int pos, uint64_t *res);
int				sum_mhelp3(uint64_t *res, int pos, int min, __uint128_t s);
void			sum_mhelp4(uint64_t *res, int pos,
	__uint128_t *s, __uint128_t f);
int				sum_mhelp5(__uint128_t *a, uint64_t *res, int pos, int min);
int				sum_mhelp6(__uint128_t *a, uint64_t *res, int pos);
char			*ft_strnewc(size_t n, char c);
char			*get_val(char *s);
size_t			ft_strlen(const char *s);
int				read_variable_char(const char *str, size_t len,
	va_list elem, t_param *f_p_s);
void			ft_string_processing(t_param *f_p_s, char *str, int flag);
int				ft_result_len_float(t_param *f_p_s, char c);
int				ft_atoi_n(const char *str, size_t *j);
char			*ft_strchr(const char *s, int c);
void			itoa_flag_handling(long long int value_i,
	unsigned long long value_u, t_param *f_p_s, t_intp *par);
void			ft_format_specification_description(const char *str, size_t len,
	va_list elem, t_param *f_p_s);
char			*ft_itoa_d_flagmin(t_intp *par, t_param **f_p_s);
char			*ft_itoa_d(long long int value_i, unsigned long long value_u,
	t_param *f_p_s, int u);
int				ft_strstr_num(const char *str, const char *to_find, size_t len);
void			ft_write_str(const char *str, size_t len);
int				read_variable_int(const char *str, size_t len, va_list elem,
	t_param *f_p_s);
int				ft_param_processing(const char *str, size_t len, va_list elem);
char			*ft_nitoa(int n);
int				ft_is_conversion(const char c);
int				ft_is_valid_param(const char c);
int				print_elem(const char *format, va_list elem);
int				ft_printf(const char *format, ...);
char			*hex_oct_main(va_list elem, t_param *form_place_spc,
	char ho, int ltype);
char			*bit_out(void *a);
char			*create_mantisfd(char *s);
char			*res_last(char *dc, char *point, int prs, int sign);
char			*float_de(t_double d, int prs, int *sign);
char			*res_last2(char *dc, char *point, int prs, int sign);
int				raz(__uint128_t num);
char			*ft_uint64toa(uint64_t a, int d);
char			*ft_uint64toa2(uint64_t a, int d);
char			*float_lde(t_double d, int prs, int *sign);
char			*bit_help(va_list elem);
char			*float_ldg(t_double d, int prs, int *sign);
char			*float_dg(t_double d, int prs, int *sign);
char			*res_last_g(char *dc, char *pt, int prs, int sign);
char			*res_last3_g(char *point, int prs, int sign);
char			*res_last4_g(char *des, char *point, int sign);
char			*drob1_new(char *s, size_t m1, int *max_d);
char			*get_point_part(char *m, int p, int t);
char			*res_last_new(char *dec, char *point, int prs, int sign);
char			*new_float_ld(t_double d, int prs);
char			*new_float_d(t_double d, int prs);
char			*get_float_all(char *m, int p, int prs, int sign);
char			*res_last_new(char *dec, char *point, int prs, int sign);
char			*get_dec_part(char *m, int p);
char			*cr_dc_new(char *s, size_t m1, int max_deg, int i);
char			*drob1_new(char *s, size_t m1, int *max_d);
char			*get_point_part(char *m, int p, int t);
char			*get_point_part2(char *m, int t);
void			get_mantis_d(t_double d, char *s, int type);
__uint128_t		pow_5(int n);
void			init_help5(__uint128_t *s, __uint128_t *c, int *i, int deg);
void			umn5_1(uint64_t *tmp, int deg, int *min, int ndb);
void			umn5(uint64_t *tmp, int deg, int *min, int ndb);
char			*cr_sdc_drob(uint64_t *a, int min, size_t m1, int max_deg);
int				col_zero(uint64_t *a, int min, size_t m1, int max_deg);
void			umn10(uint64_t *tmp, int deg, int *min, int ndb);
void			pres2(int *a, char **s, char **d);
void			pres1(int *a, char *s, char *p, int t);
int				check_c(char *s);
int				umpres(__uint128_t *a, uint64_t *tmp, int pos);
void			break_umn(uint64_t *tmp, int pos, int *min, __uint128_t s);
int				help_umn(uint64_t *tmp, int pos, __uint128_t f, __uint128_t *s);
void			init_help(__uint128_t *s, __uint128_t *c, int *i, int deg);
void			ft_free_str(char *s1, char *s2);
void			lib_int_help(int *i, t_param *f_p_s, int u);
void			printf_help1(size_t *len, const char **ptr,
	const char **str, size_t *i);
void			printf_help(size_t *i, size_t *len);
void			printf_help2(size_t *i, const char **str, va_list elem);
void			help_octa1(char *buf);
char			octa_intc(char *s);
void			get_mm(void *a, char *s);
char			*get_point_part(char *m, int p, int t);
char			*drob1_new(char *s, size_t m1, int *max_d);
char			*cr_dc_new(char *s, size_t m1, int max_deg, int i);
void			par_help3(const char *str, size_t *i,
	t_param *f_p_s, va_list elem);
char			*read_help_1(const char *str, size_t len,
	va_list elem, t_param *f_p_s);
char			*read_hex_help1(const char *str, size_t *i,
	va_list elem, t_param *form_place_spc);
void			read_char_help(char *ptr, va_list elem, t_param *f_p_s);
char			*get_float_all_e(char *m, int p, int prs, int sign);
int				read_variable_int1(const char *str, size_t len,
	va_list elem, t_param *form_place_spc);
int				num_zer(char *point);
void			form_spec_help01(const char *str, va_list elem,
	t_param *f_p_s, size_t *i);
void			check_null_ptr(char **ptr, t_param *f_p_s);
void			point_hex_help(int *i, char *res, char *buf, void *a);
void			octa_int_help(int ltype, int *i, char *res, char *buf);
void			hex_oct_main_help(char ho, int ltype, long long a, char **ptr);
char			*okrug_zero(char **r, int sign);
void			help_okrug_zero(int *i, char *s, int key, char *p);

#endif

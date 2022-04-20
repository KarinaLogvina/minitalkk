/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urosby <urosby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:55:20 by karinalogvi       #+#    #+#             */
/*   Updated: 2021/12/24 20:27:28 by urosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(char c);
int		ft_print_nbr(int n);
int		ft_print_str(char *s);
int		ft_print_hex(unsigned int num, char format);
int		ft_format(va_list apgs, const char format);
void	ft_put_hex(unsigned int num, const char format);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(char *str);
int		ft_hex_size(unsigned int num);
char	*ft_itoa(int n);
int		ft_print_percent(void);
int		ft_print_unsigned(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		intlen(int n);
int		uintlen(unsigned int n);
int		ft_pointer_size(unsigned long num);
int		ft_print_pointer(unsigned long num);
void	ft_put_pointer(unsigned long num);

#endif
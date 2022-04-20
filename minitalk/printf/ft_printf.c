/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urosby <urosby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:27:14 by karinalogvi       #+#    #+#             */
/*   Updated: 2021/12/24 20:26:09 by urosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list apgs, const char format)
{
	int	i;

	i = 0;
	if (format == '%')
	{
		write(1, "%", 1);
		i = 1;
	}
	else if (format == 'c')
		i += ft_print_char(va_arg(apgs, int));
	else if (format == 's')
		i += ft_print_str(va_arg(apgs, char *));
	else if (format == 'd' || format == 'i')
		i += ft_print_nbr(va_arg(apgs, int));
	else if (format == 'x' || format == 'X' )
		i += ft_print_hex(va_arg(apgs, unsigned int), format);
	else if (format == 'p')
		i += ft_print_pointer(va_arg(apgs, unsigned long));
	else if (format == 'u')
		i += ft_print_unsigned(va_arg(apgs, unsigned int));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		result;

	va_start(args, str);
	count = 0;
	result = 0;
	while (str[count])
	{
		if (str[count] == '%')
		{
			result += ft_format(args, str[count + 1]);
			count++;
		}
		else
			result += ft_print_char(str[count]);
		count++;
	}
	va_end(args);
	return (result);
}

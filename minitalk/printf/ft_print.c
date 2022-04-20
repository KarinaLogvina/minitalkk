/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urosby <urosby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:38:15 by urosby            #+#    #+#             */
/*   Updated: 2021/12/18 17:51:11 by urosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_nbr(int n)
{
	int		len;
	char	*number;

	len = 0;
	number = ft_itoa(n);
	len = ft_print_str(number);
	free (number);
	return (len);
}

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_print_str("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_hex(unsigned int num, char format)
{
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_put_hex(num, format);
	return (ft_hex_size(num));
}

int	ft_print_pointer(unsigned long num)
{
	int	i;

	i = 0;
	i += ft_print_str("0x");
	ft_put_pointer(num);
	i += ft_pointer_size(num);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urosby <urosby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:54:11 by urosby            #+#    #+#             */
/*   Updated: 2021/12/24 20:09:02 by urosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*number;

	len = 0;
	number = ft_uitoa(n);
	len = ft_print_str(number);
	free (number);
	return (len);
}

int	uintlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*result;
	long	buf_num;

	len = uintlen(n);
	buf_num = n;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (buf_num == 0)
		result[0] = '0';
	result[len--] = '\0';
	while (buf_num)
	{
		result[len] = buf_num % 10 + '0';
		len --;
		buf_num = buf_num / 10;
	}
	return (result);
}

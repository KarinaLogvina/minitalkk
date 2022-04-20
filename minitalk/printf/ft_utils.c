/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urosby <urosby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:37:17 by urosby            #+#    #+#             */
/*   Updated: 2021/12/24 20:22:05 by urosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	intlen(int n)
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

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	long	buf_num;

	len = intlen(n);
	buf_num = n;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (buf_num < 0)
	{
		result[0] = '-';
		buf_num = -buf_num;
	}
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

int	ft_hex_size(unsigned int num)
{
	int	size;

	size = 0;
	while (num != 0)
	{
		size++;
		num = num / 16;
	}
	return (size);
}

int	ft_pointer_size(unsigned long num)
{
	int	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		size++;
		num = num / 16;
	}
	return (size);
}

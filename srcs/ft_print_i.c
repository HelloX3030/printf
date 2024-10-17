/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:36:50 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/17 09:53:23 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_i_helper(int n)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
	{
		write(FD, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(FD, "-", 1);
		n *= -1;
		len++;
	}
	if (n <= 9)
	{
		write(FD, &"0123456789"[n], 1);
		return (++len);
	}
	else
	{
		len += ft_print_i_helper(n / 10);
		write(FD, &"0123456789"[n % 10], 1);
		return (++len);
	}
}

int	ft_print_i(va_list args)
{
	int	i;

	i = va_arg(args, int);
	return (ft_print_i_helper(i));
}

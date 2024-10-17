/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:13:54 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/17 10:27:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_print_xx_helper(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 16)
	{
		write(FD, &"0123456789ABCDEF"[n], 1);
		return (len + 1);
	}
	else
	{
		len += ft_print_xx_helper(n / 16) + 1;
		write(FD, &"0123456789ABCDEF"[n % 16], 1);
		return (len);
	}
}

int	ft_print_xx(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_print_xx_helper(n));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:41:22 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/16 09:42:26 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_p_helper(unsigned int n)
{
	int	len;

	if (n <= 16)
		write(1, &"0123456789ABCDEFG"[n], 1);
	else
	{
		len += print_p_helper(n / 10);
		write(1, &"0123456789"[n % 10], 1);
		return (len);
	}
}

int	ft_print_p(va_list args)
{
	unsigned int	n;

	n = va_arg(args, void *);
	return (print_p_helper(n));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:54:48 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/17 11:31:34 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	unsigned int	test;
	int				len1;
	int				len2;

	test = 324897;
	len1 = printf("%u \n", test);
	len2 = ft_printf("%u \n", test);
	printf("%i vs %i\n", len1, len2);
	return (0);
}

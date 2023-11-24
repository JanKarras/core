/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:03:03 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/24 16:19:08 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int nb = -21474836478123;
	char *teststr = "TestString";
	char c = 'c';
	unsigned int u = 12486362;
	int *ptr = &nb;
	if (ft_printf("MYFUCNTION\nTestStringOutPut : %s\nTestCharOutput : %c\nTestNbr_d : %d\nTestNbr_i : %i\nTest %%\nTestNbr_u : %u\nTestnbr_x : %x\nTestnbr_X : %X\nTestnbr_p : %p\nTeststr_NULL : %s\n %p\n", teststr, c, nb, nb, u, u, u, (void *)ptr, NULL, 16) == printf("CFUNCTION\nTestStringOutPut : %s\nTestCharOutput : %c\nTestNbr_d : %d\nTestNbr_i : %i\nTest %%\nTestNbr_u : %u\nTestnbr_x : %x\nTestnbr_X : %X\nTestnbr_p : %p\nTeststr_NULL : %s\n %p\n", teststr, c, nb, nb, u, u, u, (void *)ptr, NULL, 16));
		printf("Return equal");
	return (0);
}

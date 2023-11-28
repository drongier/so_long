/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:52:29 by drongier          #+#    #+#             */
/*   Updated: 2023/11/28 13:53:14 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(int i)
{
	if (i == 1)
		ft_printf("Error !! There is wrong things on the map :)\n");
	else if (i == 2)
		ft_printf("Error !! Map is not rectangular\n");
	else if (i == 3)
		ft_printf("Error !! Somethings wrong with walls\n");
	else if (i == 4)
		ft_printf("Error !! With numbers of params\n");
	else if (i == 5)
		ft_printf("Error !! Wrong Name map\n");
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:55:42 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/16 12:01:11 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf_fd(2, "Error:\nWrong input!\n");
		ft_printf_fd(2, "Input as follow: ./so_long <map_file>.ber.\n");
	}
	else if (!execution(av))
	{
		ft_printf_fd(2, "Error:\nStarting game failed\n");
		exit(0);
	}
	exit(1);
}

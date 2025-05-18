/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:05:24 by caonguye          #+#    #+#             */
/*   Updated: 2025/04/16 20:31:40 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d(void **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] != NULL)
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	free(arr);
}

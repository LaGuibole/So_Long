/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:06:51 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/06 15:00:30 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	// t_solong solong;
	t_map	map;

	if (argc != 2)
	{
		printf("Usage: %s <map_file.ber>\n", argv[0]);
	}

	if (read_map(argv[1], &map) == -1)
	{
		free_map(&map);
		ft_printf("Map not valid\n");
		return (RET_ERR);
	}
	else
		ft_printf("Map is valid\n");
	free_map(&map);
	return (RET_OK);
}

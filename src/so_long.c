/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:06:51 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/06 16:30:57 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	// t_solong solong;
	t_map	map;
	t_map	map_cpy;

	if (argc != 2)
	{
		printf("Usage: %s <map_file.ber>\n", argv[0]);
	}
	map.map_file = argv[1];
	if (read_map(&map) == -1)
	{
		free_map(&map);
		ft_printf("Map cannot be read\n");
		return (RET_ERR);
	}
	copy_map(&map, &map_cpy);
	if (!map_cpy.grid)
	{
		free_map(&map);
		ft_printf("Map copy failed\n");
		return (RET_ERR);
	}
	else
	{
		if (map_cpy.width == map.width && map_cpy.height == map.height)
		{
			int	i = 0;
			int	valid = 1;
			while (i < map.height && valid)
			{
				if (ft_strcmp(map_cpy.grid[i], map.grid[i]) != 0)
					valid = 0;
				i++;
			}
			if (valid)
				ft_printf("Map is valid and copied successfully\n");
			else
				ft_printf("Map copy failed (content mismatch)\n");
		}
		else
			ft_printf("Map copy failed (size mismatch)\n");
	}
	free_map(&map);
	free_map(&map_cpy);
	return (RET_OK);
}

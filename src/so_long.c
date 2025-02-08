/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:06:51 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/08 17:18:13 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	// t_solong solong;
	t_game	map;
	t_game	map_cpy;

	if (argc != 2)
	{
		printf("Usage: %s <map_file.ber>\n", argv[0]);
		return 0;
	}
	map.map_file = argv[1];
	if (read_map(&map) == -1)
	{
		// free_map(&map); Pas besoin de free la map si extension non valide
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
				ft_printf("Map is opened and copied successfully\n");
			else
				ft_printf("Map copy failed (content mismatch)\n");
		}
		else
			ft_printf("Map copy failed (size mismatch)\n");
	}
	if (is_rectangular(&map_cpy) == RET_ERR)
	{
		ft_printf("Error: Map is not a rectangle\n");
		free_map(&map);
		free_map(&map_cpy);
		return (RET_ERR);
	}
	else
	{
		ft_printf("Map is rectangular\n");
	}
	if (is_bordered_with_walls(&map_cpy) == RET_OK)
		ft_printf("Map is closed with 1\n");
	else
		ft_printf("Map is not closed\n");
	if (has_required_elements(&map_cpy) == RET_ERR)
		ft_printf("Error : Invalid map elements\n");
	else
		ft_printf("Map has all elements\n");
	find_player(&map);
	if (is_path_valid(&map) == RET_ERR)
		ft_printf("Map is not playable\n");
	else
		ft_printf("Map is playable, all good !\n");
	free_map(&map);
	free_map(&map_cpy);
	return (RET_OK);
}

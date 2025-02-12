/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:15:29 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/10 17:51:07 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

// static void	free_grid(t_map *map)
// {
// 	int	i;

// 	if (map->grid != NULL)
// 	{
// 		if (map->grid != NULL)
// 		{
// 			i = 0;
// 			while (i < map->height)
// 			{
// 				free(map->grid);
// 				map->grid = NULL;
// 			}
// 		}
// 	}
// }

static int	copy_grid(t_game *copy, t_game *original)
{
	int	i;

	copy->grid = malloc(sizeof(char *) * (original->m_height + 1));
	if (!copy->grid)
		return (RET_ERR);
	i = 0;
	while (i < original->m_height)
	{
		copy->grid[i] = ft_strdup(original->grid[i]);
		if (!copy->grid[i])
		{
			while (i > 0)
			{
				free(copy->grid[i - 1]);
				i--;
			}
			free(copy->grid);
			return (RET_ERR);
		}
		i++;
	}
	copy->grid[original->m_height] = NULL;
	return (RET_OK);
}

void	copy_map(t_game *original, t_game *copy)
{
	copy->map_file = original->map_file;
	if (!copy->map_file)
		return ;
	copy->m_width = original->m_width;
	copy->m_height = original->m_height;
	// copy->player_x = original->player_x;
	// copy->player_y = original->player_y;
	if (copy_grid(copy, original))
	{
		free(copy->map_file);
		free_map(copy);
		return ;
	}
	// find_player(copy);
}

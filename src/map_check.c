/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:58:26 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/06 17:16:07 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



/// @brief Check if the map is rectangular or not
/// @param map_file will be argv[1] so the map file
/// @return 1 if the map is rectangular, 0 otherwise
// int	is_map_rectangular(t_solong *map_assets)
// {
// 	int			fd;
// 	char		*line;

// 	fd = open(map_assets->map_file, O_RDONLY);
// 	if (fd < 0)
// 		return (RET_ERR);
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (close(fd), RET_ERR);
// 	map_assets->map_width = ft_strlen(line) - 1;
// 	map_assets->map_row = 0;
// 	map_assets->map = NULL;
// 	while (line)
// 	{
// 		if (ft_strlen(line) - 1 != map_assets->map_width)
// 			return (get_next_line(-1), free(line), close(fd), RET_ERR);
// 		map_assets->map_row++;
// 		line = get_next_line(fd);
// 	}
// 	return (close(fd), RET_OK);
// }




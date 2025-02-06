/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:48:44 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/06 17:59:23 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	get_map_dimensions(int fd, int *width)
{
	char	*line;
	int		line_count;

	line_count = 0;
	line = get_next_line(fd);
	if (line != NULL)
	{
		*width = ft_strlen(line);
		free(line);
		line = NULL;
		line_count++;
	}
	if (line == NULL)
		line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	return (line_count);
}

static int	populate_map_grid(int fd, t_map *map)
{
	char	*line;

	map->height = 0;
	line = get_next_line(fd);
	map->width = ft_strlen(line);
	while (line)
	{
		map->grid[map->height] = ft_strdup(line);
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	return (RET_OK);
}

int	read_map(t_map *map)
{
	int		fd;
	int		line_count;

	fd = open(map->map_file, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file\n"), -1);
	line_count = get_map_dimensions(fd, &map->width);
	map->grid = malloc(sizeof(char *) * (line_count + 1));
	if (!map->grid)
	{
		close(fd);
		perror("Memory allocation error\n");
		return (RET_NEG_ERR);
	}
	close(fd);
	fd = open(map->map_file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error reopening file\n"), -1);
	populate_map_grid(fd, map);
	map->grid[line_count] = NULL;
	close(fd);
	return (RET_OK);
}

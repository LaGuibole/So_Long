/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:48:44 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/17 17:07:30 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/messages.h"

static int	get_map_dimensions(int fd, int *width)
{
	char	*line;
	int		line_count;

	line_count = 0;
	line = get_next_line(fd);
	if (line != NULL)
	{
		*width = ft_strlen(line);
		if (line[*width -1] == '\n')
			(*width)--;
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

static int	populate_map_grid(int fd, t_game *map)
{
	char	*line;
	int		len;

	map->m_height = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		map->grid[map->m_height] = ft_strdup(line);
		free(line);
		map->m_height++;
		line = get_next_line(fd);
	}
	return (RET_OK);
}

int	read_map(t_game *map)
{
	int		fd;
	int		line_count;

	if (has_ber_extension(map))
		return (ft_putendl_fd(MSG_ERROR_EXTENSION, 2), RET_ERR);
	fd = open(map->map_file, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file\n"), -1);
	line_count = get_map_dimensions(fd, &map->m_width);
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

int	map_check(t_game *map)
{
	t_game	copy;

	copy = (t_game){};
	copy_map(map, &copy);
	if (!copy.grid)
		return (ft_putendl_fd(MSG_ERROR_COPY, 2), RET_ERR);
	if (is_rectangular(map) == RET_ERR)
		return (free_map(&copy),
			ft_putendl_fd(MSG_ERROR_RECTANGLE, 2),
			RET_ERR);
	if (is_bordered_with_walls(map) == RET_ERR)
		return (free_map(&copy), ft_putendl_fd(MSG_ERROR_WALLS, 2), RET_ERR);
	if (has_valid_elements(map) == RET_ERR)
		return (free_map(&copy), ft_putendl_fd(MSG_ERROR_INVALID, 2), RET_ERR);
	if (has_required_elements(map) == RET_ERR)
		return (free_map(&copy), ft_putendl_fd(MSG_ERROR_MISSING, 2), RET_ERR);
	if (is_path_valid(map) == RET_ERR)
		return (free_map(&copy),
			ft_putendl_fd(MSG_ERROR_UNSOLVABLE, 2),
			RET_ERR);
	free_map(&copy);
	return (ft_putendl_fd(MSG_MAP_SUCCESS, 1), RET_OK);
}

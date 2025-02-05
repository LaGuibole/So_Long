/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:58:26 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/05 11:45:02 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/// @brief A function to check if the map has .ber extension
/// @param map_file
/// @return
int	has_ber_extension(char *map_file)
{
	char	*str_cpy;

	if (!map_file || ft_strlen(map_file) <= 4)
		return (1);
	str_cpy = map_file + ft_strlen(map_file) - 4;
	return (ft_strcmp(str_cpy, ".ber"));
}

/// @brief
/// @param map_file
/// @return
int	is_map_rectangular(char *map_file)
{
	int		fd;
	char	*line;
	int		first_len;
	int		current_len;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	first_len = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
	while (line)
	{
		current_len = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
		if (current_len != first_len)
		{
			get_next_line(-1);
			return(free(line), close(fd), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}


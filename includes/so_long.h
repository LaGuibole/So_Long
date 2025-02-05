/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:08 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/04 18:52:32 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

// INCLUDES

# include "libft.h"
# include "fcntl.h"

// DEFINES

# define			RET_OK			0
# define			RET_ERR			1
# define			BAD_ARG_MSD		"Error : Bad Argument\n"
# define			USAGE			"Usage : ./so_long <file.ber>\n"


// COLORS

# define 			RED				"\033[31m"
# define 			BLUE			"\033[34m"
# define 			GREEN			"\033[32m"
# define 			RESET			"\033[0m"

// STRUCTURES

typedef struct s_solong
{

}	t_solong;

// FUNCTIONS

// ERRORS
void	usage(void);

// MAPS
int	has_ber_extension(char *str);
int	is_map_rectangular(char *map_file);

#endif

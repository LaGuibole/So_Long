/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:06:51 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/04 18:53:35 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	// if (argc < 3)
	// {
	// 	usage();
	// 	return (1);
	// }
	if (argc == 2)
	{
		if (has_ber_extension(argv[1]) == RET_OK)
			printf("Nom de map ok\n");
		if (is_map_rectangular(argv[1]) == 1)
			printf("Map rectangulaire\n");
		else
			usage();
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_so_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:16:31 by guphilip          #+#    #+#             */
/*   Updated: 2025/02/04 17:20:53 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	usage(void)
{
	ft_putstr_fd(RED BAD_ARG_MSD RESET, STDERR_FILENO);
	ft_putstr_fd(GREEN USAGE RESET, STDOUT_FILENO);
}

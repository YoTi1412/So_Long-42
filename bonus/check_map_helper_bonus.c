/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:16:22 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/27 16:16:23 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_rectangular_map(t_game *game)
{
	int		i;
	size_t	row_length;

	i = 0;
	row_length = ft_strlen(game->map.full[0]);
	while (i < game->map.rows)
	{
		if (game->map.full[i] == NULL)
		{
			ft_error_msg("Invalid Map: Row is NULL.", game);
			return ;
		}
		if (ft_strlen(game->map.full[i]) != row_length)
		{
			ft_error_msg("Invalid Map: The map is not rectangular.", game);
			return ;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:12:58 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/01 20:13:17 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_movements_shell(t_game *game)
{
	if (game->movements != game->last_printed_movements)
	{
		ft_printf(GREEN"\rMovements: %d"RESET, game->movements);
		game->last_printed_movements = game->movements;
	}
}

void	ft_print_movements_window(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}

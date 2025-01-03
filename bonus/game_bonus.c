/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:11:12 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/27 16:11:13 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_vars(t_game *game)
{
	size_t	len;
	char	*line;

	game->map.coins = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	line = game->map.full[0];
	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
		len--;
	game->map.columns = len;
	game->last_printed_movements = -1;
	game->player_sprite = RIGHT;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Couldn't find mlx pointer. Try it using a VNC.", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Couldn't create the Window.", game);
	}
}

void	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
	game->floor = ft_new_sprite(mlx, FLOOR_XPM, game);
	game->coins = ft_new_sprite(mlx, COINS_XPM, game);
	game->player_front = ft_new_sprite(mlx, PLAYER_FRONT_XPM, game);
	game->player_left = ft_new_sprite(mlx, PLAYER_LEFT_XPM, game);
	game->player_right = ft_new_sprite(mlx, PLAYER_RIGHT_XPM, game);
	game->player_back = ft_new_sprite(mlx, PLAYER_BACK_XPM, game);
	game->open_exit = ft_new_sprite(mlx, OPEN_EXIT_XPM, game);
	game->exit_closed = ft_new_sprite(mlx, EXIT_CLOSED_XPM, game);
	game->toxic = ft_new_sprite(mlx, TOXIC_RIVER_XPM, game);
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error_msg("Couldn't find a sprite. Does it exist?", game);
	return (sprite);
}

void	ft_check_map_size(t_game *game)
{
	int	screen_width;
	int	screen_height;
	int	map_width;
	int	map_height;

	mlx_get_screen_size(game->mlx_ptr, &screen_width, &screen_height);
	map_width = game->map.columns * IMG_WIDTH;
	map_height = game->map.rows * IMG_HEIGHT;
	if (map_width > screen_width || map_height > screen_height)
	{
		ft_error_msg("Invalid Map: Map size exceeds screen resolution.", game);
	}
}

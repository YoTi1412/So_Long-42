/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:58:59 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/27 15:59:00 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_command_line_args(int argc, char **argv, t_game *game)
{
	int	map_parameter_len;

	game->map_alloc = false;
	if (argc > 2)
		ft_error_msg("Too many arguments (It should be only two).", game);
	if (argc < 2)
		ft_error_msg("The Map file is missing.", game);
	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_parameter_len - 4], ".ber", 4))
		ft_error_msg("Map file extention is wrong (It should be .ber).", game);
}

void	ft_init_map(t_game *game, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The Map couldn't be opened. Does the Map exist?", game);
	map_temp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_line(map_temp, game);
	game->map.full = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}

void	ft_validate_empty_lines(char *map, t_game *game, int len)
{
	int	i;

	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map. Empty line at the beginning.", game);
	}
	if (map[len - 1] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map. Empty line at the end.", game);
	}
	i = 0;
	while (i < len - 1)
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Invalid map. Empty line in the middle.", game);
		}
		i++;
	}
}

void	ft_check_for_empty_line(char *map, t_game *game)
{
	int	len;

	if (!map)
		ft_error_msg("Invalid Map. Map is null.", game);
	len = ft_strlen(map);
	if (len == 0 || game->map.rows == 0)
		ft_error_msg("Invalid Map. The map cannot be empty.", game);
	ft_validate_empty_lines(map, game, len);
}

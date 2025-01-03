/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 02:41:05 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/31 02:41:07 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**duplicate_map(char **original, int rows)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			while (i-- > 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[rows] = NULL;
	return (copy);
}

static void	ft_flood_fill(char **map, int x, int y, int *exit_found)
{
	if (x < 0 || y < 0 || !map[x] || !map[x][y] || map[x][y] == '1' ||
		map[x][y] == 'F')
		return ;
	if (map[x][y] == 'C' || map[x][y] == '0')
		map[x][y] = 'F';
	else if (map[x][y] == 'E' || map[x][y] == 'T')
	{
		*exit_found = 1;
		return ;
	}
	ft_flood_fill(map, x, y - 1, exit_found);
	ft_flood_fill(map, x, y + 1, exit_found);
	ft_flood_fill(map, x - 1, y, exit_found);
	ft_flood_fill(map, x + 1, y, exit_found);
}

static	int	ft_check_validpath(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	valid_path(t_game *game, char **map)
{
	char	**map_copy;
	int		i;
	int		exit_found;

	exit_found = 0;
	map_copy = duplicate_map(map, game->map.rows);
	if (!map_copy)
		ft_error_msg("Memory allocation failed for map validation.", game);
	ft_flood_fill(map_copy, game->map.player.y, game->map.player.x, \
		&exit_found);
	if (!ft_check_validpath(map_copy) || !exit_found)
	{
		i = 0;
		while (map_copy[i])
			free(map_copy[i++]);
		free(map_copy);
		ft_error_msg("Invalid Map: No valid path.", game);
	}
	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
}

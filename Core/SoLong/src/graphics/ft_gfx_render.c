/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:13:30 by ibour             #+#    #+#             */
/*   Updated: 2024/11/13 13:36:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_characters_to_image(t_gamedata *gamedata, int width, int x, int y)
{
	if (gamedata->map->map[y][x] == '1')
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_wall,
			width, y * IMG_WIDTH);
	if (gamedata->map->map[y][x] == '0')
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_empty,
			width, y * IMG_WIDTH);
	if (gamedata->map->map[y][x] == 'P')
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_player,
			width, y * IMG_WIDTH);
	if (gamedata->map->map[y][x] == 'C')
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_collectible,
			width, y * IMG_WIDTH);
}

static void	ft_gfx_render_splash(t_gamedata *gamedata)
{
	mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_splash, 0, 0);
}

static void	ft_gfx_render_game(t_gamedata *gamedata)
{
	size_t	x;
	int		y;
	int		width;

	x = 0;
	y = 0;
	width = 0;
	while (gamedata->map->map[y])
	{
		while (gamedata->map->map[y][x] && gamedata->map->map[y][x] != '\n')
		{
			ft_characters_to_image(gamedata, width, x, y);
			width += IMG_WIDTH;
			x++;
		}
		width = 0;
		x = 0;
		y++;
	}
}

int	ft_gfx_render(t_gamedata *gamedata)
{
	if (gamedata->window == NULL || gamedata->mlx == NULL)
		return (-1);
	if (gamedata->window_page == WINDOW_SPLASH)
		ft_gfx_render_splash(gamedata);
	else
		ft_gfx_render_game(gamedata);
	return (0);
}
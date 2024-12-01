/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 06:39:59 by ibour             #+#    #+#             */
/*   Updated: 2024/12/01 06:47:35 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	ft_engine_reset(t_engine *engine, int fractal)
{
	engine->fractal.type = fractal;
	engine->fractal.zoom = WINDOW_SIZE / 4;
	engine->fractal.mouse_x = 0;
	engine->fractal.mouse_y = 0;
	engine->fractal.offset_x = -2;
	engine->fractal.offset_y = -2;
	engine->fractal.julia_lock = false;
	engine->fractal.color = DEFAULT_COLOR;
	engine->fractal.iterations = MIN_ITERATIONS;
}

int	ft_calculate_fractal(t_fractal *fractal, t_complex *c, int x, int y)
{
	int	i;

	i = 0;
	if (fractal->type != JULIA)
		c->i = (y / fractal->zoom) + fractal->offset_y;
	else if (!fractal->julia_lock)
		c->i = (fractal->mouse_y / fractal->zoom) + fractal->offset_y;
	if (fractal->type == MANDELBROT)
		i = calc_mandelbrot(fractal, c);
	else if (fractal->type == JULIA)
		i = calc_julia(fractal, c, x, y);
	else if (fractal->type == BURNING_SHIP)
		i = calc_burning_ship(fractal, c);
	else if (fractal->type == TRICORN)
		i = calc_tricorn(fractal, c);
	else if (fractal->type == MANDELBOX)
		i = calc_mandelbox(fractal, c);
	else if (fractal->type == CELTIC_MANDELBAR)
		i = calc_celtic_mandelbar(fractal, c);
	return (i);
}

void	ft_set_fractal(t_engine *engine, char *fractal)
{
	size_t	length;

	if (!engine || !fractal)
		return ;
	ft_strmap(fractal, ft_tolower);
	length = ft_strlen(fractal);
	if (ft_strncmp(fractal, MANDELBROT_STR, length) == 0)
		engine->fractal.type = MANDELBROT;
	else if (ft_strncmp(fractal, JULIA_STR, length) == 0)
		engine->fractal.type = JULIA;
	else if (ft_strncmp(fractal, BURNING_SHIP_STR, length) == 0)
		engine->fractal.type = BURNING_SHIP;
	else if (ft_strncmp(fractal, TRICORN_STR, length) == 0)
		engine->fractal.type = TRICORN;
	else if (ft_strncmp(fractal, MANDELBOX_STR, length) == 0)
		engine->fractal.type = MANDELBOX;
	else if (ft_strncmp(fractal, CELTIC_MANDELBAR_STR, length) == 0)
		engine->fractal.type = CELTIC_MANDELBAR;
	else
		ft_throw_error(ERROR_SYNTAX);
}

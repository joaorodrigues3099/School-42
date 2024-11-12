/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:10:09 by ibour             #+#    #+#             */
/*   Updated: 2024/11/12 13:26:27 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * Only exists because of norminette.
 *
 * @param error The type of error that occurred.
 */
static void	ft_throw_error_sub(const int error)
{
	if (error == ERROR_MAP_FILE_FORMAT)
		ft_printf("Invalid map format. Required type is .ber");
}

/**
 * Handles error messages and exits the program with
 * the error status code.
 *
 * @param error The type of error that occurred.
 */
void	ft_throw_error(const int error)
{
	ft_printf("\033[31mError: ");
	if (error == ERROR_UNKNOWN)
		ft_printf("An unknown error occured.");
	else if (error == ERROR_SYNTAX)
	{
		ft_printf("The syntax is not correct.\033[0m\n");
		ft_printf("Usage: ./so_long <map>");
	}
	else if (error == ERROR_INIT_DATA)
		ft_printf("Initialization process failed: Memory allocation.");
	else if (error == ERROR_INIT_MLX)
		ft_printf("Initialization process failed: MLX library.");
	else if (error == ERROR_INIT_HOOKS)
		ft_printf("Initialization process failed: MLX hooks.");
	else if (error == ERROR_INIT_MAP)
		ft_printf("Initialization process failed: Map initialization.");
	else if (error == ERROR_INIT_GRAPHICS)
		ft_printf("Initialization process failed: Loading images.");
	ft_throw_error_sub(error);
	ft_printf("\033[0m\n");
	exit(EXIT_FAILURE);
}

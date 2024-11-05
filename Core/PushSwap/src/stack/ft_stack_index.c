/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:20:28 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 11:21:40 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stack_index(t_stack *stack, const int num)
{
	int	i;

	i = 0;
	while (stack->num != num)
	{
		i++;
		stack = stack->next;
	}
	stack->index = 0;
	return (i);
}
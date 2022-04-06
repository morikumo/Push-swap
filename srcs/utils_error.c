/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:13:51 by mabid             #+#    #+#             */
/*   Updated: 2022/04/06 16:13:54 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_(int a)
{
	if (a == 0)
		ft_putstr("Error\n");
	return (0);
}

int	error_exit(int a)
{
	if (a == 0)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	return (0);
}

int	error_exit_free(int a, t_stack *stack_a)
{
	if (a == 0)
	{
		ft_putstr("Error\n");
		free(stack_a);
		exit(0);
	}
	return (0);
}

int	zero(int a)
{
	if (a == 0)
		return (0);
	return(0);
}


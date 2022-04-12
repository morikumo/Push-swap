/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:13:51 by mabid             #+#    #+#             */
/*   Updated: 2022/04/12 14:49:20 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t				len;

	len = 0;
	while ((unsigned char)s[len])
		len++;
	return (len);
}

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

int	error_exit2(int a)
{
	if (a == 0)
		exit(0);
	return (0);
}

int	error_exit_free(int a, char **tab, t_stack *stack_a)
{
	if (a == 0)
	{
		ft_putstr("Error\n");
		free_str(tab);
		free_stack(stack_a);
		exit(0);
	}
	return (0);
}

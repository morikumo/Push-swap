/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:51:51 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 15:53:51 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Verifie si le caractères est bien numérique
 * 
 * @param s 
 * @return int 
 */
int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * @brief Verifie si le caractère est bien un whitespaces.
 * 
 * @param c 
 * @return int 
 */
int	ft_white_space(char c)
{
	if (c != '\f' && c != '\v' && c != '\n'
		&& c != '\r' && c != ' ' && c != '\t')
		return (1);
	else
		return (0);
}

/**
 * @brief Verifie si l'argument passé au programme est bon. 
 * Avec comme limites INT_MIN et INT_MAX.
 * si le dernier arg est un '-'
 * 
 * 
 * @param str 
 */
int	check_str(char *str)
{
	int		i;
	int		size;
	long	stock;

	i = 0;
	size = 0;
	while (str[i])
	{
		size = ft_strlen(str);
		stock = ft_atol(str);
		if (str[size - 1] == '-')
			return (1);
		if (!stock)
			return (0);
		if (stock > 2147483647 || stock < -2147483648)
			return (0);
		if (ft_isdigit(str[i]) == 0
			&& ft_white_space(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (0);
}

/**
 * @brief Va verifier les doublons a travers la liste 
 * en passant par les elements donner.
 * 
 * @param stack_a 
 */
void	check_doublon(t_stack *stack_a)
{
	int		nbr;
	t_stack	*start;
	t_stack	*two;
	t_stack	*compare;

	start = stack_a;
	two = stack_a;
	while (start)
	{
		nbr = start->nbr;
		compare = two->next;
		while (compare)
		{
			if (nbr == compare->nbr)
			{
				ft_putstr("Error\n");
				free_stack(stack_a);
				exit (1);
			}
			compare = compare->next;
		}
		start = start->next;
		two = two->next;
	}
}

/**
 * @brief Vérifie si le prochain nbr existe bien 
 * et si il est inférieur au précedent.
 * 
 * @param stack_a 
 * @return int 
 */
int	check_next(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->nbr < stack_a->next->nbr && stack_a->next != NULL)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

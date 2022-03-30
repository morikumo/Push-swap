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
 * 
 * @param str 
 */
void	check_str(char *str)
{
	int		i;
	long	stock;

	i = 0;
	while (str[i])
	{
		stock = ft_atol(str);
		if (stock > 2147483647 || stock < -2147483648)
		{
			ft_putstr("Error av too large\n");
			exit(1);
		}
		if (ft_isdigit(str[i]) == 0
			&& ft_white_space(str[i]) && str[i] != '-')
		{
			ft_putstr("Error av arn't a correct one\n");
			exit(1);
		}
		i++;
	}
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
				ft_putstr("Error double av\n");
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

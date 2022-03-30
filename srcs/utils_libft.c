/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:19:19 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 17:21:48 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Le bon vieux putstr, j'aurai tout de meme preferer printf
 * 
 * @param s 
 */
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

/**
 * @brief Un simple swap
 * 
 * @param a 
 * @param b 
 */
void	ft_swap(long *a, long *b)
{
	long	c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * @brief Nous donne la taille de la liste. Equivalent de lstsize.
 * 
 * @param stack_a 
 * @return int 
 */
int	len_list(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int		error_exit(int a)
{
	if (a == 0)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	return (0);
}

/**
 * @brief Un atoi pour les long. 
 * Va nous permettre de prendre en compte 
 * les chiffre plus grand que INT_MAX et INT_MIN.
 * 
 * @param str 
 * @return long 
 */
long	ft_atol(const char *str)
{
	int		i;
	int		negatif;
	long	resultat;

	i = -1;
	negatif = 1;
	resultat = 0;
	while (str[++i])
    {
        if(!((ft_isdigit(str[i]) == 1) || (str[i] == '-') 
		|| (str[i] == ' ')))
			return(error_exit(0));
        else if(str[i] == '-' && (!(ft_isdigit(str[i + 1]) == 1) 
		|| (ft_isdigit(str[i - 1]) == 1)))
			return(error_exit(0));
        else if(str[i] == '-')
            negatif = -negatif;
        if(ft_isdigit(str[i]) == 1)
            resultat = resultat * 10 + str[i] - 48;
    }
	if(((negatif * resultat) > (2147483647)) 
	|| ((negatif * resultat) < (-2147483648)) )
		return(error_exit(0));
	return (resultat * negatif);
}

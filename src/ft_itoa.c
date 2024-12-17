/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:40:58 by lorey             #+#    #+#             */
/*   Updated: 2024/11/07 01:30:40 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_digits(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	full_tab(char *result, int *count, int *n)
{
	result[*count] = '\0';
	while (*count > 0)
	{
		result[*count - 1] = (*n % 10) + '0';
		*n /= 10;
		(*count)--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		count;

	count = count_digits(n);
	result = malloc(sizeof(char) * (count + 1));
	if (!result)
		return (0);
	full_tab(result, &count, &n);
	return (result);
}

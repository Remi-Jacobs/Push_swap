/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:17:34 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 12:01:58 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && \
		(i == 0 || ft_isspace(str[i - 1])) && ft_isdigit(str[i + 1]))
			i++;
		else if (ft_isdigit(str[i]))
			i++;
		else if (ft_isspace(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_duplicate(long *a, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	checkint(long *a, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (a[i] > INT_MAX || a[i] < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	final_check(char *str, long *a)
{
	int	c;
	int	size;

	size = num_count(str);
	c = 0;
	if (!checkint(a, size))
		c++;
	if (!check_duplicate(a, size))
		c++;
	return (c);
}

char	**pre_num_catch(char *str)
{
	char	*remove_spaces;
	char	**result;

	if (!check_string(str))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	remove_spaces = (remove_extra_spaces(str));
	if (remove_spaces == NULL)
		return (NULL);
	result = ft_split(remove_spaces, ' ');
	if (result == NULL)
	{
		free (remove_spaces);
		return (NULL);
	}
	free(remove_spaces);
	return (result);
}

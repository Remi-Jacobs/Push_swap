/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:21:01 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 12:03:13 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static char	*check_space(const char *str, char *result)
{
	int		space_found;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	space_found = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
		{
			if (space_found == 0)
			{
				result[j++] = ' ';
				space_found = 1;
			}
		}
		else
		{
			result[j++] = str[i];
			space_found = 0;
		}
		i++;
	}
	return (result);
}

char	*remove_extra_spaces(const char *str)
{
	const char	*temp;
	size_t		len;
	char		*result;

	len = 0;
	while (ft_isspace(*str))
		str++;
	temp = str;
	while (*temp != '\0')
	{
		if (!ft_isspace(*temp))
			len++;
		else if (*(temp + 1) != '\0' && !ft_isspace(*(temp + 1)))
			len++;
		temp++;
	}
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result = check_space(str, result);
	result[len] = '\0';
	return (result);
}

int	num_count(const char *str)
{
	int	count;
	int	on_off;
	int	i;

	i = 0;
	count = 0;
	on_off = 0;
	while (str[i])
	{
		if (on_off == 0 && str[i] >= '0' && str[i] <= '9')
		{
			on_off = 1;
			count++;
		}
		if (!(str[i] >= '0' && str[i] <= '9'))
			on_off = 0;
		i++;
	}
	return (count);
}

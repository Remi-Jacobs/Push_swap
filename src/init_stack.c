/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:18:32 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 12:03:17 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	insertatend(t_stack **a, int nbr)
{
	t_stack	*cursor;
	t_stack	*tail;

	cursor = malloc(sizeof(t_stack));
	if (cursor == NULL)
		return ;
	cursor->data = nbr;
	cursor->next = NULL;
	if (*a == NULL)
	{
		cursor->prev = NULL;
		*a = cursor;
		return ;
	}
	tail = *a;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = cursor;
	cursor->prev = tail;
}

static long	*catch_number(char *str)
{
	char	**sub_str;
	size_t	c;
	size_t	i;
	long	*answer;

	i = 0;
	c = 0;
	answer = (long *)malloc(sizeof(long) * num_count(str));
	if (answer == NULL)
		return (NULL);
	sub_str = pre_num_catch(str);
	if (sub_str == NULL)
		exit(1);
	while (sub_str[c])
	{
		answer[i++] = ft_atol(sub_str[c]);
		free(sub_str[c]);
		c++;
	}
	free(sub_str);
	return (answer);
}

void	init_stack_a(t_stack **a, char *argv)
{
	size_t	i;
	size_t	j;
	long	*result;

	j = 0;
	result = catch_number(argv);
	if (final_check(argv, result) != 0)
	{
		write(2, "Error\n", 6);
		free(result);
		return ;
	}
	i = num_count(argv);
	while (i > 0)
	{
		insertatend(a, result[j]);
		i--;
		j++;
	}
	free(result);
}

static size_t	calculate_total_length(int argc, char **argv)
{
	size_t	total_len;
	int		i;

	total_len = 0;
	i = 1;
	while (i < argc)
	{
		total_len += ft_strlen(argv[i]) + 1;
		i++;
	}
	return (total_len);
}

char	*combine_args(int argc, char **argv)
{
	char	*combined_args;
	size_t	total_len;
	int		i;

	if (argc <= 1)
		return (NULL);
	if (argc == 2 && argv[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	total_len = calculate_total_length(argc, argv);
	combined_args = malloc(total_len);
	if (combined_args == NULL)
		return (NULL);
	combined_args[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strlcat(combined_args, argv[i], total_len);
		if (i < argc - 1)
			ft_strlcat(combined_args, " ", total_len);
		i++;
	}
	return (combined_args);
}

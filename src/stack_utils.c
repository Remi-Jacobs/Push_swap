/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:17:29 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 12:03:47 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_len(t_stack	*stack)
{
	int	count;

	count = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack	*find_min(t_stack *stack)
{
	long	nbr;
	t_stack	*cursor;

	if (!stack)
		return (NULL);
	nbr = LONG_MAX;
	cursor = NULL;
	while (stack)
	{
		if (stack->data < nbr)
		{
			nbr = stack->data;
			cursor = stack;
		}
		stack = stack->next;
	}
	return (cursor);
}

t_stack	*find_max(t_stack	*stack)
{
	long	nbr;
	t_stack	*cursor;

	if (!stack)
		return (NULL);
	nbr = LONG_MIN;
	cursor = NULL;
	while (stack)
	{
		if (stack->data > nbr)
		{
			nbr = stack->data;
			cursor = stack;
		}
		stack = stack->next;
	}
	return (cursor);
}

t_stack	*find_last(t_stack	*stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

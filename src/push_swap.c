/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:17:34 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 12:03:21 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *target, char stack_name)
{
	if (!stack || !*stack || !target)
	{
		ft_printf("Error: Invalid stack or target in prep_for_push\n");
		return ;
	}
	while (*stack != target)
	{
		if (target->index < stack_len(*stack) / 2)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void	free_stack(t_stack	*a)
{
	t_stack	*current;
	t_stack	*temp;

	current = a;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	char	*combined_args;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	combined_args = combine_args(argc, argv);
	if (combined_args != NULL)
	{
		init_stack_a(&a, combined_args);
		free(combined_args);
	}
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(a);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	t_stack *a = NULL;
// 	t_stack *b = NULL;

// 	// Combine the command line arguments into a single string
// 	char *combined_args = combine_args(argc, argv);
// 	if (combined_args != NULL)
// 	{
// 		init_stack_a(&a, combined_args);
// 		free(combined_args); // Free the combined string after use
// 	}
// 	ft_printf("%d, %d\n", stack_len(a),stack_len(b));
// 	push(&a, &b);
// 	ft_printf("%d, %d\n", stack_len(a),stack_len(b));
// 	t_stack *current = a;
// 	while (current != NULL)
// 	{
// 		printf("%d ", current->data);
// 		t_stack *temp = current;
// 		current = current->next;
// 		free(temp); // Free the memory for each node in stack a
// 	}
// 	printf("\n");

// 	current = b;
// 	while (current != NULL)
// 	{
// 		printf("%d ", current->data);
// 		t_stack *temp = current;
// 		current = current->next;
// 		free(temp); // Free the memory for each node in stack b
// 	}
// 	printf("\n");

// 	return 0;
// }
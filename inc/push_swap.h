/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:19:15 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/29 19:11:28 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*swap_target;

}	t_stack;

char	*combine_args(int argc, char **argv);
void	init_stack_a(t_stack **a, char *argv);
int		num_count(const char *str);
char	*remove_extra_spaces(const char *str);
char	**pre_num_catch(char *str);
int		final_check(char *str, long *a);
int		stack_len(t_stack	*stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack	*stack);
t_stack	*find_last(t_stack	*stack);
void	index_assignement(t_stack	*head);
void	setup_a(t_stack *a, t_stack	*b);
void	setup_b(t_stack *a, t_stack *b);
void	sort_stacks(t_stack **a, t_stack **b);
int		stack_sorted(t_stack *a);
void	sort_three(t_stack **a);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	sa(t_stack	**a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:25:38 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/26 12:48:16 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define ERROR -1
# define SUCCESS 0

# define TRUE 1
# define FALSE 0

typedef struct s_numcheck
{
	int			n1;
	int			n2;
	int			n3;
	int			n4;
	int			n5;
}				t_numcheck;

typedef struct s_data
{
	int			pivotb;
	int			pivots;
	int			ranum;
	int			rbnum;
	int			pnum;
	int			i;
}				t_data;

typedef struct s_ps
{
	struct s_ps	*prev;
	struct s_ps	*next;
	int			value;
	char		*command;
}				t_ps;

int		check_and_save_data(int argc, char **str, t_ps **a);
void	free_string(char **str);
void	free_list(t_ps **a);

void	ft_swap(int *a, int *b);
int		ft_lstadd_back_ps(t_ps **lst, int value, char *command);
int		ft_lstadd_front_ps(t_ps **lst, int value, char *command);
void	ft_lstdel_back_ps(t_ps **lst);
void	ft_lstdel_front_ps(t_ps **lst);

int		sa(t_ps **a, int flag, t_ps **res);
int		sb(t_ps **b, int flag, t_ps **res);
int		pa(t_ps **a, t_ps **b, t_ps **res);
int		pb(t_ps **a, t_ps **b, t_ps **res);
int		ra(t_ps **a, int flag, t_ps **res);
int		rb(t_ps **b, int flag, t_ps **res);
int		rra(t_ps **a, int flag, t_ps **res);
int		rrb(t_ps **b, int flag, t_ps **res);
int		ss(t_ps **a, t_ps **b, t_ps **res);
int		rr(t_ps **a, t_ps **b, t_ps **res);
int		rrr(t_ps **a, t_ps **b, t_ps **res);

void	init_data(t_data *data);

void	sort_two_a(t_ps **temp, t_ps **res);
void	sort_two_b(t_ps **temp, t_ps **res);
void	sort_under_three_a(int len, t_ps **a, t_ps **b, t_ps **res);
void	sort_under_three_b(int len, t_ps **a, t_ps **b, t_ps **res);

void	do_pa(t_ps **a, t_ps **b, t_ps **res, int len);
void	sort_three_a_onestack(t_ps **temp, t_ps **res);
void	sort_three_b_onestack(t_ps **a, t_ps **b, t_ps **res);

void	sort_three_a(t_ps **temp, t_ps **res);
void	sort_three_b(t_ps **a, t_ps **b, t_ps **res);

void	sort_four_a(t_ps **a, t_ps **b, t_ps **res);
void	sort_four_b(t_ps **a, t_ps **b, t_ps **res);
void	sort_five_a(t_ps **a, t_ps **b, t_ps **res);
void	sort_five_b(t_ps **a, t_ps **b, t_ps **res);

int		ft_pivot(t_ps *a, t_data *data, int len);
int		ft_pivot_for_45(t_ps *a, int len);
int		is_sorted(t_ps **list, int len, int flag);

void	a_to_b(int r, t_ps **a, t_ps **b, t_ps **res);
void	b_to_a(int r, t_ps **a, t_ps **b, t_ps **res);

int		get_list_length(t_ps **lst);

void	delete_next_two(t_ps *temp);
int		insert_middle(t_ps *temp, char *command);
void	remove_command(t_ps **res);

#endif

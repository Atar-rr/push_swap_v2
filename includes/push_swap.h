//
// Created by Latesha Monkfish on 22/02/2020.
//

#ifndef PUSH_SWAP_SORT_MORE_5_ELEM_H
#define PUSH_SWAP_SORT_MORE_5_ELEM_H

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/libft.h"

typedef struct			s_stack
{
	int					num;
	struct s_stack		*next;
	struct s_stack		*previous;
}						t_stack;

typedef struct			s_command
{
	char				command[4];
	struct s_command	*next;
}						t_command;

typedef struct			s_link_list
{
	size_t				size;
	t_stack				*head;
	t_stack				*tail;
}						t_l_list;

typedef struct			s_tmp
{
	int					swap_num1;
	int					swap_num2;
	int 				opora;
	int 				list_size;
	int 				count_step_top;
	int 				count_step_bot;
	int 				count_swap;
	int					chunk;
	int 				chunk_step;
	int 				chunk_parts;
	int 				flag_swap_top_or_bot;
	int 				i;
	int 				opora2;
}						t_tmp;

int						save_stack(char **av, int ac, t_l_list *stack_a);
int						move_stack(t_l_list *stack_a);
void					*init_link_list(t_l_list **list);
t_stack 				*lst_new(char *date);
void					push_back(t_l_list *list, t_stack *node);
void					push_front(t_l_list *list, t_stack *node);
void					*lst_del_front(t_l_list *list);
void					*lst_del_back(t_l_list *list);
void					swap_rra_or_rrb(t_l_list *stack);
void					swap_rra_and_rrb(t_l_list *stack_a, t_l_list *stack_b);
void					swap_ra_or_rb(t_l_list *stack);
void					swap_ra_and_rb(t_l_list *stack_a, t_l_list *stack_b);
void					swap_pa_or_pb(t_l_list *stack_out, t_l_list *stack_in);
void					swap_a_or_b(t_l_list *stack);
void					swap_a_and_b(t_l_list *stack_a, t_l_list *stack_b);
void					*create_sort_array(t_l_list *stack);
void					*init_tmp_list(t_tmp **list);
void					print_stack(t_l_list *stack_a, t_l_list *stack_b, char *command);
int 					stack_is_sort(t_l_list *stack, const int *sorted_array, int stack_size);
void					sort_more_5_elem(t_l_list *stack_a, const int *sort_array);
void					sort_less_three_elem(t_l_list *stack_a);
void					print_command(char *command);
void					sort_stack(t_l_list *stack_a, t_l_list *stack_b, const int *sort_array, t_tmp *tmp);
void					sort_stack_b(t_l_list *stack_a, t_l_list *stack_b, const int *sort_arr);
int						swap_from_top_fast(t_l_list *stack_1, t_l_list *stack_2, int option);
int						swap_from_top(t_l_list *stack_1, t_l_list *stack_2, int swap_num1, int swap_num2, int option);
int						swap_from_bot(t_l_list *stack_1, t_l_list *stack_2, int swap_num1, int swap_num2, int option);
int						validate_stack(char **av, int ac, t_l_list *stack_a);
#endif //PUSH_SWAP_SORT_MORE_5_ELEM_H

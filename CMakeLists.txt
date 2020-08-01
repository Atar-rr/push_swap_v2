cmake_minimum_required(VERSION 3.16)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

link_directories(./ )


add_executable(push_swap src/print_stack.c  src/push_swap/sort_more_5_elem.c includes/push_swap.h src/swap_command.c src/create_lists.c src/save_stack.c src/create_sort_array.c libftprintf/libft/ft_qsort.c src/push_swap/main.c src/push_swap/print_command.c src/push_swap/sort_less_three_elem.c src/stack_is_sort.c src/push_swap/sort_stack_a.c src/push_swap/swap_top_slow_and_fast.c src/push_swap/swap_from_bot.c src/push_swap/sort_stack_b.c)
add_executable(checker libftprintf/libft/get_next_line.c src/checker/main.c src/save_stack.c src/create_lists.c src/checker/move_stack.c libftprintf/libft/ft_qsort.c src/swap_command.c src/create_sort_array.c src/stack_is_sort.c src/print_stack.c libftprintf/libft/ft_atoi_long_long.c libftprintf/libft/len_numer_arr.c libftprintf/libft/ft_strsplit.c libftprintf/libft/ft_len_word.c libftprintf/libft/ft_strsub.c libftprintf/libft/ft_count_word)

target_link_libraries(push_swap libftprintf.a)
target_link_libraries(checker  libftprintf.a)

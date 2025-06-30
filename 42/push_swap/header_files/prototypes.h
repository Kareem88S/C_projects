/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:26:44 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/25 17:26:44 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "push_swap.h"

// -----------------------------------------------------------------------------
/*								STRUCTS										  */
/*							controller.h									  */
typedef struct s_stack_status	t_stack_status;
typedef struct s_controller	t_ctr;
/*							linked_list_node.h								  */
typedef struct s_node_statistics	t_node_stats;
typedef struct s_stack_node	t_n;
/*							five_element_sorter.h							  */
typedef struct s_five_sorter_meta_data_struct	t_5s_meta;
/*							quick_sort.h									  */
typedef struct s_quick_sort_meta	t_quick;


// -----------------------------------------------------------------------------
/*								ENUMS										  */
/*							macros.h										  */
enum			size_limits;
typedef enum 	e_lives_in_which_stack t_stack;
/*							move_operations.h								  */
typedef enum 	e_moves t_mv;
// -----------------------------------------------------------------------------
/*								FUNCTIONS									  */
/*								--------									  */
/*						**	0_src_support	**								  */
/*						1_free_functions.c									  */
/*						2_check_top_swap.c									  */
/*						3_get_extremes.c									  */
/*						4_normalizing_array.c								  */
/*						5_build_array.c										  */
/*						6_utils.c											  */
void	error_msg_free_all(t_ctr *tcon);
void	free_all(t_ctr *tcon);
void	free_and_null(void **ptr);
// int		check_top_swap(t_ctr *tcon);
// void 	get_extremes(t_stack stack, const int *values_arr, int *extremes_index, int meta[2]);
int		normalize_array(int *normalized, int *original, int stack_size);
int		get_perc(int data_chunk, int stack_size);
t_n		**get_stack_top(t_ctr *tcon, t_stack stack);
int		abs_value(int value);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

/*								--------									  */
/*					**	src_1_preps	**										  */
/*						1_controller.c										  */
/*						2_validate_input_parse_into_array.c					  */
/*						3_validate_dups_and_normalize_values.c				  */
/*						4_parse_into_circ_linked_list.c						  */
t_ctr	*preset_tcon(t_ctr *tcon, int argc, char *argv[], char ***user_input);
int		validate_input_parse_into_array(t_ctr *tcon, int argc, char **user_input);
int		validate_dups_and_normalize_values(t_ctr *tcon);									
int		parse_into_circ_linked_list(t_ctr *tcon);
void	set_static_node_statistics(t_n *node, int stack_size);

/*								--------									  */
/*					**	src_2_update_data	**								  */
/*						1_update_program_state.c							  */
/*						2_update_tcon.c										  */
/*						3_update_tcon_utils_off_and_buckets.c				  */
int		update_global_state(t_ctr *tcon);
int		update_sub_state(t_stack_status *stats);
// int	update_sub_state(t_ctr *tcon, t_n *const *top_origin, t_n *const *top_aux, t_stack_status *stats);
// void	update_node_data(t_n *node, int index, int stack_size);
// int		update_global_stack_nodes(t_ctr *tcon, t_n *a_node, t_n *b_node);
// void	update_tcon(t_ctr *tcon);
// void	get_all_other_tcon_percentages(t_ctr *tcon);
// int	update_tcon_sub_stack(t_n *const *top_or, t_n *const *top_aux, t_stack_status *stats);

/*								--------									  */
/*					**	src_3_move_operations	**							  */
/*						1_push_operation.c									  */
/*						2_swap_operation.c									  */
/*						3_rotate_operation.c								  */
/*						4_print_operation.c									  */
/*						5_moving.c											  */
t_mv	push_move(t_ctr *tcon, t_mv cmd);
t_mv	swap_move(t_ctr *tcon, t_mv cmd);
t_mv	rotate_move(t_ctr *tcon, t_mv cmd);
void	print_operation(t_mv cmd);
int		moving(t_ctr *tcon, t_stack stack, t_mv move);

/*					**	src_4_sorting_algos	**								  */
/*						1_sorting_manager.c									  */
/*						2_mini_sort_base_case.c								  */
/*						3_three_elements_sorter.c							  */
/*						4_four_elements_sorter.c							  */
/*						5_five_elements_sorter.c							  */
/*						6 utils file										  */
/*						7_four_bucket_sort.c								  */
/*						8 utils file										  */
/*					9	8_quick_sort.c										  */
//						9_two_off.c 
// int		sorting_manager(t_ctr *tcon, t_n *top_node, int cur_stack_size);
// int		sorting_manager(t_ctr *tcon, t_n *const *top_node, int cur_stack_size);
// int		sorting_manager(t_ctr *tcon, t_n *const *top_orig, int cur_stack_size, int &dont_push);
int		sorting_manager(t_ctr *tcon, t_n *const *top_orig, int cur_stack_size, int *dont_push);
// int		sorting_manager(t_ctr *tcon, t_n *const *top_orig, t_n *const *top_aux, int cur_stack_size);
// int		mini_sort(t_ctr *tcon, t_n *top_node, int stack_size);
// int		mini_sort(t_ctr *tcon, t_n *const *top_n, int stack_size);
// int		mini_sort(t_ctr *tcon, t_n *const *or, t_n *const *aux, t_stack_status *stats);
int		mini_sort(t_ctr *tcon, t_stack_status *stats);
int		*get_ranks(t_stack stack, const int *values, int *ranks, int size);
int		two_element_sort(t_ctr *tcon, t_stack_status *stats);
// int		two_element_sort(t_ctr *tcon, t_n *top, t_n *bot);
// int		three_element_sort(t_ctr *tcon, t_n *top_n, t_n *mid_n, t_n *bot_n);
// int		three_element_sort(t_ctr *tcon, int *nums, int total_size);
int		three_element_sort(t_ctr *tcon, t_stack_status *stats, int *ranks);
// int		three_element_sort(t_ctr *tcon, t_stack_status *stats);
// int		three_element_sort(t_ctr *tcon, int *nums, t_stack stack, int tot_size);
// int		three_element_sort(t_ctr *tcon, t_n *node, int *nums, t_stack stack);
// int		four_element_sort(t_ctr *tcon, t_n *const *node, int *nums);
// int		four_element_sort(t_ctr *tcon, t_n *const *n, int *nums, int is_sub_stack);
int		four_element_sort(t_ctr *tcon, t_stack_status *stats, int *ranks);
// int		four_element_sort(t_ctr *tcon, t_n *const *n, t_stack_status *stats, int *ranks);
// int		five_element_sort(t_ctr *tcon, t_n *top);
// int		five_element_sort(t_ctr *tcon, t_n *const *n_or, t_n *const *n_aux, int *nums);
// int		five_element_sort(t_ctr *tcon, t_n *const *or, t_n *const *aux, t_stack_status *stats);
int		five_element_sort(t_ctr *tcon, t_stack_status *stats, int *ranks);
int		simple_insertion_sort(t_ctr *tcon, t_n *top_n, int chunk_size);
int		insertion_max_two_off(t_ctr *tcon, t_stack_status *stats);
// int		bucket_four_sort(t_ctr *tcon, t_n *top, int sortable_size);
// int		bucket_sort(t_ctr *tcon, t_n *const *origin_top_node, t_n *const *auxiliary_top_node, t_stack_status *stats);
int		bucket_sort(t_ctr *tcon, t_stack_status *stats);
// int		bucket_four_sort(t_ctr *tcon, t_n *const *origin_top_node, t_n *const *auxiliary_top_node, int sortable_size);
// int		quick_sort(t_ctr *tcon, t_stack stack, t_n *top_node, int chunk_size, int times_looped);
int		quick_sort(t_ctr *tcon, t_stack_status *s);
// int		reverse_sort(t_ctr *tcon, t_n *top, int size);
// int		reverse_sort(t_ctr *tcon, t_n *const *top, int size);
// int		reverse_sort(t_ctr *tcon, t_n *const *top_or, t_n *const *top_au, int size);
int		reverse_sort(t_ctr *tcon, t_stack_status *s);
// int		max_two_off(t_ctr *tcon, t_n *const *top_or, t_n *const *top_au, int size);
int		max_two_off(t_ctr *tcon, t_stack_status *stats);
/*						1_push_operation.c									  */
#endif
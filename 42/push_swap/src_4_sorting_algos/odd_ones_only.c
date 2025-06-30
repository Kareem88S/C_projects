


/*
// HOW TO START

General idea:
Sort per bucket.
Mostly sorted already.
all must be in their rightful bucket already. 
	if not, get them in the right ones
Check neighbors for suitable leader, 
	If possible, swap. But before swap, lock swap until stack b is checked
			for swap -- better ss (both stacks) than first sa then sb.
	During the first rotation, stack b is monitored for pushing back into a.



If within reasonable bucket-range, check neighbors, 
	most closely to destination bucket. 
	If possible, swap. But before swap, lock swap until stack b is checked
		for swap -- better ss (both stacks) than first sa then sb.
During the first rotation, stack b is monitored for pushing back into a.


First checks if node is in right bucket (10 buckets).
	If node is more than x (3?) buckets away, push to b stack.
*/





// void	insertion_sort(t_ctr *tcon)//, char a_b_offset)
// {
// 	// start with only pushing odd ones out svp

// 	// suitable_targets_insertion(tcon);
// 	// update_best_move_insertion(tcon);
// 	// update_distance_to_target(tcon);

// 	tcon->which_rotation++;
// 	tcon->which_rotation_this_algo++;
// 	update_stack_nodes(tcon);		//ch
// 	update_tcon(tcon);					// ch
// 	update_leader_scores_global(tcon);	// WIP	

// 	// update_suitability_scores(tcon);	// ch	
// 	find_target_nodes(tcon);
	
	
	
// 	i = -1;
// 	while (++i < tcon->total_elements)
// 	{
// 		node = tcon->stack_arr[i];
// 		node->best_mv->target_node_up_global = NULL;
// 		node->best_mv->target_node_up_short_term = NULL;
// 		node->best_mv->target_node_low_global = NULL;
// 		node->best_mv->target_node_low_short_term = NULL;
// 		if (abs(node->off_by) > 0)
// 			find_target_nodes(tcon, tcon->stack_arr[i]);
// 	}

// 	i = -1;
// 	while (++i < tcon->total_elements)
// 		update_distance_to_target(tcon->stack_arr[i]);
// 	// external, van src_2_upd->5_upd_distance
	

// 	return ;
// }




// // /*
// // 		!!!!!!!		Verzet naar update dir (5) 		!!!!!!!
// // 					Copy worthy voor algo specific? nmlk shortterm ipv global
// //
// // Determines if a node is suitable target as leader. If this node is at its ideal position,
// // 	other nodes may follow it to reach their ideal position.
// // */
// // static void	update_suitability_scores(t_ctr *tcon)
// // {
// // 	int	i;
// // 	t_n	*node;

// // 	i = -1;
// // 	while (++i < tcon->total_elements)
// // 	{
// // 		node = tcon->stack_arr[i];
// // 		node->target_score = 0;
// // 		calculate_divergence_score(node);
// // 	}
// // }

// /*
// The closer to the ideal position, the higher the ranking, the more suitable
// 	for other nodes to follow its position.
// Ranks suitability based on
// 	- quarter position
// 	- tenth position
// 	- general position
// First, resets the score.
// Ranking between -3 and 14
// Boosting cheap nodes (rr/rrr)
// */
// static void	calculate_divergence_score(t_n *node)
// {
// 	const int	stack_size = node->this_stack_size;
// 	int			quarter_divergence;
// 	int			tenth_divergence;
// 	int			final_pos_divergence;

// 	node->target_score = 0; // double..
// 	quarter_divergence = abs(node->in_which_quarter - node->belongs_in_quarter);
// 	tenth_divergence = abs(node->in_which_tenth - node->belongs_in_tenth);
// 	final_pos_divergence = abs(node->normalized_value - node->pos_in_stack);
// 	if (quarter_divergence == 0)
// 		node->target_score += 4;
// 	else if (quarter_divergence == 1)
// 		node->target_score += 2;
// 	if (tenth_divergence == 0)
// 		node->target_score += 3;
// 	if (tenth_divergence <= 2)
// 		node->target_score += 2;
// 	if (final_pos_divergence <= 3)
// 		node->target_score += 3;
// 	else if (final_pos_divergence <= 6)
// 		node->target_score += 1;
// 	if (node->pos_in_stack == stack_size - 1)
// 		node->target_score += 2;
// 	if (node->pos_in_stack == stack_size - 2 || node->pos_in_stack == 0)
// 		node->target_score += 1;
// }



// static void	find_target_nodes_global(t_ctr *tcon, t_n *node)
// {
// 	int		i;
// 	t_n		*candidate;
// 	int		best_score_up = -1;
// 	int		best_score_down = -1;

// 	i = -1;
// 	while (++i < tcon->total_elements)
// 	{
// 		node->best_mv->target_node_up_global = NULL;
// 		node->best_mv->target_node_up_short_term = NULL;
// 		node->best_mv->target_node_low_global = NULL;
// 		node->best_mv->target_node_low_short_term = NULL;
// 		candidate = tcon->stack_arr[i];
// 		if (node == candidate)
// 			continue ;
// 		if (candidate->lives_in_stack == node->lives_in_stack)
// 		{

// 		}
// 				// actually, check if in sorted order, as well as other stack. Always try SS
// 				continue;

// 			if (candidate->target_score > best_score_up
// 				&& candidate->normalized_value > node->normalized_value)
// 			{
// 				best_score_up = candidate->target_score;
// 				node->best_mv->target_node_up_global = candidate;
// 				node->best_mv->target_node_up_short_term = candidate;
// 			}
// 			if (candidate->target_score > best_score_down
// 				&& candidate->normalized_value < node->normalized_value)
// 			{
// 				best_score_down = candidate->target_score;
// 				node->best_mv->target_node_low_global = candidate;		// long term
// 				node->best_mv->target_node_low_short_term = candidate;	// short term
// 			}
// 		}
// 		node->best_mv.target_node_up_global = best_up;
// 		node->best_mv.target_node_low_global = best_down;

// 	// optionally also search short-term targets here (based on move counts or urgency)
// 	node->best_mv.target_node_up_short_term = best_up; // for now, same
// 	node->best_mv.target_node_low_short_term = best_down; // for now, same
// }












// // ------------
// // Maybe keep no of rotations? "original best move && updated best move"

// /*
// Idea:
// Whenever possible, perform SS. Need SA/SB? lock until SS or ignore (field in best_move)
// ORRR
// Check %% out of accepted bucket. if tiny percent, keep those as base-elements in A. 
// Push all to stack B. Accept for bottom 3, 4, or 5.. (rotate if come accross.)


// DUS

// At start, 
// 0) determine accepted bucket (lets say 1 off is fine.)
// So 20 elements
// Bucket 0 -- 0, 1
// bucket 1 -- 2, 3
// bucket 9 -- 18, 19
// Accepted elements per bucket to be pushed to B
// Bucket 0 -- 18, 19, 0, 1, 2, 3
// bucket 1 -- 0, 1, 2, 3, 4, 5
// bucket 9 -- 16, 17, 18, 19, 0, 1

// 1) check if in or around accepted bucket.
// 	if yes -> push to B
// 	if no
// 		check if bucket -1 (1 verder dan accepted)
// 		if yes -> rotate (forw) then return after next element
// 		if no
// 	rotate to ignore
// 1.5 -- meanwhile always monitor SS
// etcet

// 2) 





// */




// /*
// Oud
// Step 1: Classify Nodes into Buckets (10 Buckets)
// Divide numbers into 10 buckets based on their value range.

// Each node’s bucket is determined based on min & max values of the stack.

// Step 2: Process Stack A
// Check if a node belongs in its bucket.

// If more than X (3?) buckets away, move it to Stack B.

// If within a reasonable range, check neighbors:

// If a swap brings it closer, prepare a swap.

// Before swapping, check Stack B for a potential better ss move.

// Step 3: Optimize Swaps (ss > sa + sb)
// Before swapping (sa or sb), check if ss is better.

// A swap should only occur if it helps both stacks simultaneously.

// Step 4: Monitor Stack B for Re-insertion
// During the first full rotation, observe Stack B.

// If a node in B is ready for A, push it ASAP.

// Keep track of optimal push positions (don’t just push back immediately).

// Step 5: Final Pass for Remaining Elements
// Once B is mostly empty, insert remaining nodes carefully.

// If any elements are still out of place, perform a final insertion pass.
// */
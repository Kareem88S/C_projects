# either by including the filename.gdb
# or auto-include it by changing name to .gdbinit

# define cur_state_A
# 	printf "top-A: %p, n-val: %d | prev: %p, n-val: %d | prev->prev: %p, val: %d\n", \
# 		tcon->a_top, tcon->a_top->normalized_value, \
# 		tcon->a_top->previous, tcon->a_top->previous->normalized_value, \
# 		tcon->a_top->previous->previous, tcon->a_top->previous->previous->normalized_value
# 		# some comment
# 	printf "bottom-A: %p, n-val: %d | next: %p, %d | next->next: %p, %d\n", \
# 		tcon->a_bottom, tcon->a_bottom->normalized_value, \
# 		tcon->a_bottom->next, tcon->a_bottom->next->normalized_value, \
# 		tcon->a_bottom->next->next, tcon->a_bottom->next->next->normalized_value
# end

#stack a snapshot

# Automatically start full recording when hitting the breakpoint


break 7_reverse_sort.c:64
# Automatically start full recording when hitting the breakpoint
commands
  record full
end

define win_src
	winheight src 20
end

define cur_state_A
  set $node = tcon->a_top
  printf "Stack A: "

  if ($node != 0)
    # Print the first element (a_bottom)
    printf "%d", $node->normalized_value
    set $node = $node->previous

    while ($node != tcon->a_top)
      printf ", %d", $node->normalized_value
      set $node = $node->previous
    end

    printf "\n"
  else
    printf "(empty stack)\n"
  end

  printf "top-A: %p, n-val: %d | prev: %p, n-val: %d | prev->prev: %p, val: %d\n", \
    tcon->a_top, tcon->a_top->normalized_value, \
    tcon->a_top->previous, tcon->a_top->previous->normalized_value, \
    tcon->a_top->previous->previous, tcon->a_top->previous->previous->normalized_value

  printf "bottom-A: %p, n-val: %d | next: %p, %d | next->next: %p, %d\n", \
    tcon->a_bottom, tcon->a_bottom->normalized_value, \
    tcon->a_bottom->next, tcon->a_bottom->next->normalized_value, \
    tcon->a_bottom->next->next, tcon->a_bottom->next->next->normalized_value
end

# stack b snapshot
define cur_state_B
  set $node = tcon->b_top
  printf "Stack B: "

  if ($node != 0)
    # Print the first element (a_bottom)
    printf "%d", $node->normalized_value
    set $node = $node->previous

    while ($node != tcon->b_top)
      printf ", %d", $node->normalized_value
      set $node = $node->previous
    end

    printf "\n"
  else
    printf "(empty stack)\n"
  end

	printf "top-B: %p, n-val: %d | prev: %p, n-val: %d | prev->prev: %p, val: %d\n", \
		tcon->b_top, tcon->b_top->normalized_value, \
		tcon->b_top->previous, tcon->b_top->previous->normalized_value, \
		tcon->b_top->previous->previous, tcon->b_top->previous->previous->normalized_value

	printf "bottom-B: %p, n-val: %d | next: %p, %d | next->next: %p, %d\n", \
		tcon->b_bottom, tcon->b_bottom->normalized_value, \
		tcon->b_bottom->next, tcon->b_bottom->next->normalized_value, \
		tcon->b_bottom->next->next, tcon->b_bottom->next->next->normalized_value
end


# track the broken node
define watch_node9
  set $cur = tcon->a_top
  set $start = $cur
  while ($cur->normalized_value != 9)
    set $cur = $cur->next
    if ($cur == $start)
      printf "Node with normalized_value == 9 not found!\n"
      return
    end
  end
  printf "Found node at %p with normalized_value == 9\n", $cur
  set $watched = $cur
  watch $watched->lives_in_stack
  watch $watched->next
  watch $watched->previous
  printf "Watchpoints set on lives_in_stack, next, and previous of node %p\n", $watched
end

# break src_4_sorting_algos/1_sorting_manager.c:27
# break 1_sorting_manager.c:27
# break 3_three_elements_sorter.c:28
# break 3_three_elements_sorter.c:54
# break 3_three_elements_sorter.c:80
# break 4_four_elements_sorter.c:40


# break 8_quick_sort.c:34
# # Automatically start full recording when hitting the breakpoint
# commands
#   record full
# end



# if .gdbinit does not initiate automatically:
# Force loading the file with "-x .gdbinit ./program" flag
#		gdb ./program -x .gdbinit
#			NB: order uninportant, as just flags.
# or simply create a .gdb file -- loaded in the same way
# "my_gdb_file.gdb"
#		gdb ./program -x my_gdb_file.gdb
#				or
#		gdb -x my_gdb_file.gdb ./program
//
//  cmd_handler.c
//  push_swap_in_xcode
//
//  Created by Chan on 2022/11/30.
//

#include "../push_swap.h"

void cmd(t_cmd_case cmd, t_stack *stack_a, t_stack *stack_b)
{
	if (cmd == SA) {
		swap(stack_a, stack_b, SA);
	} else if (cmd == SB) {
		swap(stack_a, stack_b, SB);
	} else if (cmd == SS) {
		swap(stack_a, stack_b, SS);
	} else if (cmd == PA) {
		push(stack_a, stack_b, PA);
	} else if (cmd == PB) {
		push(stack_a, stack_b, PB);
	} else if (cmd == RA) {
		rotate(stack_a, stack_b, RA);
	} else if (cmd == RB) {
		rotate(stack_a, stack_b, RB);
	} else if (cmd == RR) {
		rotate(stack_a, stack_b, RR);
	} else if (cmd == RRA) {
		reverse_rotate(stack_a, stack_b, RRA);
	} else if (cmd == RRB) {
		reverse_rotate(stack_a, stack_b, RRB);
	} else if (cmd == RRR) {
		reverse_rotate(stack_a, stack_b, RRR);
	}
}

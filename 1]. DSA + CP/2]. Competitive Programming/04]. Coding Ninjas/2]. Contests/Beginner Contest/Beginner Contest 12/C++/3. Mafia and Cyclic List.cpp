/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the size of the list.
*/

// Helper function to calculate number of nodes in LinkedList Cycle.
int loopNodes(Node *current)
{
	// Integer variable 'res' to store result.
    int res = 1;

    // Pointer 'temp' to point to the provided parameter.
    Node *temp = current;

    // Iterating till the 'temp' return to 'current'.
    while (temp->next != current)
    {
        res++;
        temp = temp->next;
    }

    // Return 'res' as the final count.
    return res;
}

Node* findKthNode(Node* head, int k) {

	// Pointers 'slow' and 'fast' pointing to the head.
	Node *slow = head, *fast = head;

	// Move 'slow' by 1 step.
    slow = slow->next;

    // Move 'fast' by 1 step.
    fast = fast->next->next;

    // Integer variable to store number of nodes in the LinkedList cycle.
	int nodesInLoop = 0;

	// Iterate while 'fast' and 'fast->next' aren't 'NULL'.
    while (fast != NULL && fast->next != NULL) {

    	/* If the 'slow' and 'fast' pointer meet, they are sure
    	to have met at a node which lies inside the cycle of the LinkedList.
    	From any of the two pointers, we call the helper function 'loopNodes' to calculate
    	the number of nodes in this cycle and break out of the while loop. */
        if (slow == fast){
           	nodesInLoop = loopNodes(slow);
			break;
		}

		// Move 'slow' by 1 step.
        slow = slow->next;
        
        // Move 'fast' by 2 steps.
        fast = fast->next->next;
    }

    // Node variable 'startOfCycle' to denote the starting of the LinkedList Cycle.
	Node* startOfCycle = slow;

	// 'iterator' will be used to traverse the LinkedList 'k' steps efficiently.
	Node* iterator = head;

	// Store number of steps 'k' in the variable 'step'.
  	int steps = k;

  	// Iterate until we either exhaust 'steps' or we are at the beginning of the cycle.
	while (steps--) {
		iterator = iterator->next;
		if (iterator == startOfCycle){
			break;
		}
	}
	
    // If there are steps remaining, it implies we have to move in the cycle now.
	if (steps > 0) {
		
        // Reduce the number of 'steps' to be traversed.
		steps %= nodesInLoop;
		
        // Move the left over 'steps' using the iterator.
		while (steps--) {
			iterator = iterator->next;
		}
	}

	// Return 'iterator' as the final output.
	return iterator;
}
/*
    Time complexity: O(N)
    Space complexity: O(1)

    where 'N' is the size of the given list.
*/

bool isVowel(char c) {
	return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

Node* vowelConsonant(Node* head) {
	// Create two pointers, 'vowel' and 'consonant', and initialise them with NULL.
	Node *vowel = NULL, *consonant = NULL; 
	Node *current, *previousVowel = NULL, *previousConsonant = NULL;

	// Initialize 'current' with head.
	current = head;

	// Traverse in the given list.
	while(current) {
		// If current character is vowel.
		if(isVowel(current -> val)) {
			// If the 'previousVowel' is not NULL, then mark the next pointer of the 'previousVowel' to the 'current'.
			if(previousVowel) {
				previousVowel -> next = current;
			}
			// If the 'previousVowel' is NULL, mark the 'vowel' to 'current'.
			else {
				vowel = current;
			}
			previousVowel = current;
		}
		else {
			// If the 'previousConsonant' is not NULL, then mark the next pointer of the 'previousConsonant' to the 'current'.
			if(previousConsonant) {
				previousConsonant -> next = current;
			}
			// If the 'previousConsonant' is NULL, mark the 'consonant' to 'current'.
			else {
				consonant = current;
			}
			previousConsonant = current;
		}
		current = current -> next;
	}

	// If 'previousVowel' is not NULL, then mark the next pointer of 'previousVowel' to 'consonant'.
	if(previousVowel) {
		previousVowel -> next = consonant;
	}

	// If 'previousConsonant' is not NULL, then mark the next pointer of 'previousConsonant' to NULL.
	if(previousConsonant) {
		previousConsonant -> next = NULL;
	}

	// If 'vowel' is not NULL, return 'vowel' as the answer, otherwise, return 'consonant'.
	if(vowel) {
		return vowel;
	}
	return consonant;
}
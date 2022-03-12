# Check palidrome in any sequence of characters with recursion
# It will return "True" or "False" after checking
def palindrome_checker(sequence):

    def chars(sequence):
        sequence = sequence.lower()
        ans = ''

        for char in sequence:
            if char in 'abcdefghijklmnopqrstuvxwyz1234567890':
                ans = ans + char

        return ans

    def check(sequence):
        if len(sequence) <= 1:
            return True

        else:
            return sequence[0] == sequence[-1] and check(sequence[1:-1])

    return check(chars(sequence))

print(palindrome_checker('2022/22/02'))
# OUTPUT: True
print(palindrome_checker("Madam, in Eden, I'm Adam"))
# OUTPUT: True

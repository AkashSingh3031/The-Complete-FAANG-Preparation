
# Contributed by Paraj Shah
# https://github.com/parajshah

def alternatingCharacters(s):
    count = 0
    for i in range(len(s) - 1):
        if (s[i] == 'A' and s[i + 1] == 'B') or  (s[i] == 'B' and s[i + 1] == 'A'):
            continue
        count += 1
    return count
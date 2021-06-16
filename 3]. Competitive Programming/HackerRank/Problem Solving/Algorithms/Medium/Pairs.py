
# Contributed by Paraj Shah
# https://github.com/parajshah

def pairs(k, arr):
    return len(set(arr) & set([item + k for item in set(arr)]))
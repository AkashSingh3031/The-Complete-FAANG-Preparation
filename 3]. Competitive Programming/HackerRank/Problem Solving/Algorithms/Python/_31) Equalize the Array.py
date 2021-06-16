
# Contributed by Paraj Shah
# https://github.com/parajshah

def equalizeArray(arr):
    return len(arr) - max([arr.count(i) for i in set(arr)])
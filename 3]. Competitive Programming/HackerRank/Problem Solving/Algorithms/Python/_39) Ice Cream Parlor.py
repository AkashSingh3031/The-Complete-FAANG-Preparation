
# Contributed by Paraj Shah
# https://github.com/parajshah

def icecreamParlor(m, arr):
    d = {}
    for i in range(len(arr)):
        if m - arr[i] in d:
            return [d[m - arr[i]], i + 1]
        else:
            d[arr[i]] = i + 1
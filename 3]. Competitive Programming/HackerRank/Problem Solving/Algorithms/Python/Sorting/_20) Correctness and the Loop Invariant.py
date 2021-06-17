
# Contributed by Paraj Shah
# https://github.com/parajshah

def insertion_sort(l):
    for i in range(1, len(l)):
        j = i-1
        key = l[i]
        # Add an equal symbol to the condition (j > 0) => (j >= 0)
        while (j >= 0) and (l[j] > key):
           l[j+1] = l[j]
           j -= 1
        l[j+1] = key

m = int(input().strip())
ar = [int(i) for i in input().strip().split()]
insertion_sort(ar)
print(" ".join(map(str,ar)))
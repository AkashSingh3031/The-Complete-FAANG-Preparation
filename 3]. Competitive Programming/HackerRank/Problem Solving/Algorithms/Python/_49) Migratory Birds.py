
# Contributed by Paraj Shah
# https://github.com/parajshah

def migratoryBirds(arr):
    counts = {}
    # Make a hash table to store values of counts
    for i in arr:
        if i in counts:
            counts[i] += 1
        else:
            counts[i] = 1
    # Find max key
    m = max(counts.values())
    minKey = 10000
    for key, value in counts.items():
        if value == m:
            if minKey > key:
                minKey = key                
    return minKey
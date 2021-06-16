
# Contributed by Paraj Shah
# https://github.com/parajshah

def countingSort(arr):
    counts = [0] * 100
    for i in arr:
        counts[i] += 1
    
    answer = []
    for i in range(len(counts)):
        while counts[i] > 0:
            counts[i] -= 1
            answer.append(i)
    return answer
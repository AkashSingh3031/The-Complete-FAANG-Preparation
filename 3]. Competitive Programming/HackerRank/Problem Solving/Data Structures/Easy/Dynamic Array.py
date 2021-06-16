
# Contributed by Paraj Shah
# https://github.com/parajshah

def dynamicArray(n, queries):
    arr = [[] for _ in range(n)]
    lastAnswer = 0
    answers = []
    
    for i in range(len(queries)):        
        if queries[i][0] == 1:
            x,y = queries[i][1], queries[i][2]
            idx = (x ^ lastAnswer) % n
            arr[idx].append(y)
        else:
            x,y = queries[i][1], queries[i][2]
            idx = (x ^ lastAnswer) % n
            lastAnswer = arr[idx][y % len(arr[idx])]
            answers.append(lastAnswer)
            
    return answers
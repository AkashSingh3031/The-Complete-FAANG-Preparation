
# Contributed by Paraj Shah
# https://github.com/parajshah

def breakingRecords(scores):
    minimum = scores[0]
    maximum = scores[0]
    countMin = 0
    countMax = 0
    for i in range(1,len(scores)):
        if scores[i] < minimum:
            minimum = scores[i]
            countMin += 1
        if scores[i] > maximum:
            maximum = scores[i]
            countMax += 1
    return countMax,countMin
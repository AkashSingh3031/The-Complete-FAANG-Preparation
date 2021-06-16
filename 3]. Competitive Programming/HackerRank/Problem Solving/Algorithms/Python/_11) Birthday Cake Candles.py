
# Contributed by Paraj Shah
# https://github.com/parajshah

def birthdayCakeCandles(ar):
    m = max(ar)
    count = 0
    for i in range(len(ar)):
        if ar[i] == m:
            count += 1
    return count
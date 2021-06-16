
# Contributed by Paraj Shah
# https://github.com/parajshah

def getTotalX(a, b):
    x = max(a)
    count = 0
    y = min(b)
    
    for i in range(x,y+1):
        for j in range(len(a)):
            # Check if number is multiple of all elements in array a
            if not i % a[j] == 0:
                break
            # If YES..
            if j == len(a) - 1:
                # Check if number is factor of all elements in array b
                for k in range(len(b)):
                    if not b[k] % i == 0:
                        break
                    # If YES..
                    if k == len(b) - 1:
                        count += 1       
    return count
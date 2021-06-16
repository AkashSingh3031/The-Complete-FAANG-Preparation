
# Contributed by Paraj Shah
# https://github.com/parajshah

def hourglassSum(arr):
    SUM = []
    
    for i in range(len(arr) - 2):
        for j in range(len(arr) - 2):
            SUM.append(arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2])
            
    return max(SUM)

# Consider 3x3 array
# [i][j]      [i][j + 1]      [i][j + 2]
# [i + 1][j]  [i + 1][j + 1]  [i + 1][j + 2]
# [i + 2][j]  [i + 2][j + 1]  [i + 2][j + 2]

# We consider these indices for the hourglass calculation
# [i][j]      [i][j + 1]      [i][j + 2]
#             [i + 1][j + 1]
# [i + 2][j]  [i + 2][j + 1]  [i + 2][j + 2]
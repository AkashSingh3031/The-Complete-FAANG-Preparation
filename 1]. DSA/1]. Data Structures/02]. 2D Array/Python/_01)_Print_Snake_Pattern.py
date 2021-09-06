"""
Output:
    Snake Pattern =
    1 2 3 4
    8 7 6 5
    9 10 11 12
    16 15 14 13
"""


def printSnake(matrix):
    for x in range(len(matrix)):
        if (x + 1) % 2 == 0:
            for y in range(1, len(matrix[0]) + 1):
                print(matrix[x][-y], end=" ")
        else:
            for y in range(len(matrix[0])):
                print(matrix[x][y], end=" ")
        print()


print("Snake Pattern =")
matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]

printSnake(matrix)

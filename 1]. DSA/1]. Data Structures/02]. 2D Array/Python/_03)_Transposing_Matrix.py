"""
Output:
    Transpose of Matrix =
    1 5 9 13
    2 6 10 14
    3 7 11 15
    4 8 12 16
"""


def transpose_matrix(matrix):
    for x in range(len(matrix)):
        for y in range(len(matrix)):
            print(matrix[y][x], end=" ")
        print()


print("Transpose Matrix =")
matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]

transpose_matrix(matrix)

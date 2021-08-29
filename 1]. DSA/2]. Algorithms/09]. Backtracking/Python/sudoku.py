def print_grid(arr):
    for i in range(9):
        for j in range(9):
            print (arr[i][j], end = " ")
        print()

def find_empty_location(arr, l):
    for row in range(9):
        for col in range(9):
            if arr[row][col] == 0:
                l[0] = row
                l[1] = col
                return True
    return False

def used_in_row(arr, row, num):
    for i in range(9):
        if (arr[row][i] == num):
            return True
    return False

def used_in_col(arr, col, num):
    for i in range(9):
        if (arr[i][col] == num):
            return True
    return False

def used_in_box(arr, row, col, num):
    for i in range(3):
        for j in range(3):
            if (arr[i + row][j + col] == num):
                return True
    return False

def check_location_is_safe(arr, row, col, num):
    return not used_in_row(arr, row, num) and not used_in_col(arr, col, num) and not used_in_box(arr, row - row % 3, col - col % 3, num)


def solve_sudoku(arr):

    l = [0, 0]

    if (not find_empty_location(arr, l)):
        return True
    
    row = l[0]
    col = l[1]

    for num in range(1, 10):

        if (check_location_is_safe(arr, row, col, num)):
            arr[row][col] = num

            if (solve_sudoku(arr)):
                return True

            arr[row][col] = 0

    return False


if __name__=="__main__":
     
    # creating a 2D array for the grid
    grid =[[0 for x in range(9)]for y in range(9)]
     
    grid =[[3, 0, 6, 5, 0, 8, 4, 0, 0],
          [5, 2, 0, 0, 0, 0, 0, 0, 0],
          [0, 8, 7, 0, 0, 0, 0, 3, 1],
          [0, 0, 3, 0, 1, 0, 0, 8, 0],
          [9, 0, 0, 8, 6, 3, 0, 0, 5],
          [0, 5, 0, 0, 9, 0, 6, 0, 0],
          [1, 3, 0, 0, 0, 0, 2, 5, 0],
          [0, 0, 0, 0, 0, 0, 0, 7, 4],
          [0, 0, 5, 2, 0, 6, 3, 0, 0]]
     
    
    if(solve_sudoku(grid)):
        print_grid(grid)
    else:
        print("No solution exists")
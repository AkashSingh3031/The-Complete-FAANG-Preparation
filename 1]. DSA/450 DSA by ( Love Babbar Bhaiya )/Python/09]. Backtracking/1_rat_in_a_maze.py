def isSafe(row, col, Array, visited, N):
    if  (row == -1 or row == N) or\
        (col == -1 or col == N) or\
        (visited[row][col]) or\
        Array[row][col] ==0:
        
        return False
    return True

def pathsUntil(row, col, Array, N, visited, path, paths):

    if  (row == -1 or row == N) or\
        (col == -1 or col == N) or\
        visited[row][col] or\
        (Array[row][col] ==0):

        return 
    
    # If reached the destination
    if (row == N - 1) and (col == N - 1):
        paths.append(path)
        return 

    # This node is visited
    visited[row][col] = True

    #left move
    if isSafe(row, col + 1, Array, visited, N):
        path += "L"
        pathsUntil(row, col + 1, Array, N, visited, path, paths )
        path = path[: -1]    # backtrack
    
    #right move
    if isSafe(row, col - 1, Array, visited, N):
        path += "R"
        pathsUntil(row, col - 1, Array, N, visited, path, paths )
        path = path[: -1]    # backtrack

    #down move
    if isSafe(row + 1, col, Array, visited, N):
        path += "D"
        pathsUntil(row + 1, col, Array, N, visited, path, paths )
        path = path[: -1]    # backtrack
    
    #top move
    if isSafe(row - 1, col, Array, visited, N):
        path += "U"
        pathsUntil(row - 1, col, Array, N, visited, path, paths )
        path = path[: -1]    # backtrack

    # After all the depth clean its trace of visited
    visited[row][col] = False
    
def printPaths(Array, N):
    visited = [ [False for i in range(N)] for i in range(N)]
                
    path = ""
    paths = []
    pathsUntil(0, 0, Array, N, visited, path, paths)
    return paths

# Main Input
Array = [ [1, 0, 0, 0], 
          [1, 1, 0, 1], 
          [1, 1, 0, 0], 
          [0, 1, 1, 1] ]
N = len(Array)

print(printPaths(Array, N))

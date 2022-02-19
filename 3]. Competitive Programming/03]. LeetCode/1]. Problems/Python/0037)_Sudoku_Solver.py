class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not any(['.' in x for x in board]):
            return
        minset = set(range(10))
        mx,my = 0,0
        for (i,j) in itertools.product(range(9),range(9)):
            if board[i][j] == '.':
                rset = set(board[i])
                cset = set([board[x][j] for x in range(9)])
                blockset = set([board[x][y] for (x,y) in itertools.product(range(int(i/3)*3,int(i/3)*3+3),range(int(j/3)*3,int(j/3)*3+3))])
                ac = set()
                for d in range(1,10):
                    d = str(d)
                    if d not in rset and d not in cset and d not in blockset:
                        # board[i][j]  = d
                        ac.add(d)
                if len(ac) < len(minset):
                    minset = ac
                    mx,my = i,j
        for x in minset:
            board[mx][my] = x
            self.solveSudoku(board)
            if not any(['.' in x for x in board]):
                return
            board[mx][my]='.'
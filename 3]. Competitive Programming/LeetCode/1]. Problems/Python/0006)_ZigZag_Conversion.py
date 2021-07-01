class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        zigzag = [[] for _ in range(numRows)]
        row = 0
        direction = -1
        
        for c in s:
            zigzag[row].append(c)
            if row == 0 or row == numRows-1:
                direction = -direction
            row += direction
        return "".join([c for r in zigzag for c in r])
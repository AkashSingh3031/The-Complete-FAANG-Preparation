class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix[::] = zip(*matrix[::-1])
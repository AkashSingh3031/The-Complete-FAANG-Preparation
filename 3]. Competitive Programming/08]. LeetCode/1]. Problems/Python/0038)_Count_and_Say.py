class Solution:
    def countAndSay(self, n: int) -> str:
        s = '1'
        for _ in range(n - 1):
            s = ''.join(str(len(list(group))) + digit for digit, group in itertools.groupby(s))
        return s
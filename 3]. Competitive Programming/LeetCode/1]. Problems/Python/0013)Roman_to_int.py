class Solution:
    #s is a str which represents roman number
    #returns int which is alternative to roman number
    def romanToInt(self, s):
        d = {
             "M": 1000,
            "CM": 900,
            "D": 500,
            "CD": 400,
             "C": 100,
            "XC": 90,
            "L": 50,
            "XL": 40,
            "X": 10,
            "IX": 9,
            "V": 5,
            "IV": 4,
            "I": 1,
        }
        size = len(s)
        num = 0
        i = 0
        while i < size:
            x = s[i:min(size, i+2)]
            if x in d:
                num += d[x]
                i+=1
            else:
                num += d[s[i]]
            i+=1
        return num
                

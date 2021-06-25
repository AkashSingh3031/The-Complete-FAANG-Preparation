class Solution:
    #num is int
    #return str which is the roman alternative to num
    def intToRoman(self, num):
        symbol = {1: 'I', 4: 'IV', 5: 'V', 9: 'IX', 10: 'X', 40: 'XL', 50: 'L', 90: 'XC', 100: 'C', 400: 'CD', 500: 'D', 900: 'CM', 1000: 'M'}
        listi = list(symbol.keys())
        listi.reverse()
       
        string =''
        num1 = num
        
        for k in listi:
            
            tim = num//k
            
            string += symbol[k]*tim
            
            num %= k
            
        return string
                

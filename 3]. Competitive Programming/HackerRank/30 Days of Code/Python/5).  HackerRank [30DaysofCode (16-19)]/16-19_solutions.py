##### 17th Solution
#--------------------------------------------------

#!/bin/python3
import sys
S = input().strip()
try:
    print(int(S))
except:
    print("Bad String")

##### 18th Solution
#------------------------------------------------------

class Calculator:
    def power(self, n, p):
        if n<0 or p<0:
            raise ValueError("n and p should be non-negative")
        return n**p
myCalculator=Calculator()
T=int(input())
for i in range(T):
    n,p = map(int, input().split())
    try:
        ans=myCalculator.power(n,p)
        print(ans)
    except Exception as e:
        print(e)   

##### 19th Solution
#---------------------------------------------------------

import sys

class Solution:
    def __init__(self):
        self.mystack = list()
        self.myqueue = list()
        return None

    def pushCharacter(self, char):
        self.mystack.append(char)

    def popCharacter(self):
        return self.mystack.pop(-1)

    def enqueueCharacter(self, char):
        self.mystack.append(char) 

    def dequeueCharacter(self):
        return self.mystack.pop(0)
# read the string s
s=input()
#Create the Solution class object
obj=Solution()   

l=len(s)
# push/enqueue all the characters of string s to stack
for i in range(l):
    obj.pushCharacter(s[i])
    obj.enqueueCharacter(s[i])
    
isPalindrome=True
'''
pop the top character from stack
dequeue the first character from queue
compare both the characters
''' 
for i in range(l // 2):
    if obj.popCharacter()!=obj.dequeueCharacter():
        isPalindrome=False
        break
#finally print whether string s is palindrome or not.
if isPalindrome:
    print("The word, "+s+", is a palindrome.")
else:
    print("The word, "+s+", is not a palindrome.")    

##### 20th Solution
#-------------------------------------------------------------------

class AdvancedArithmetic(object):
    def divisorSum(n):
        raise NotImplementedError

class Calculator(AdvancedArithmetic):
    def divisorSum(self, n):
        p = e = 0
        for i in range(1, 1001):
            e = n%i
            if e == 0:
                p += i
        return p
        pass

n = int(input())
my_calculator = Calculator()
s = my_calculator.divisorSum(n)
print("I implemented: " + type(my_calculator).__bases__[0].__name__)
print(s)
##### 21st Solution
#---------------------------------------------------------------

#!/bin/python3
import sys
n = int(input().strip())
a = list(map(int, input().strip().split(' ')))
swaps = 0 
is_sorted = False

while not is_sorted:
    is_sorted = True
    for i in range(0, len(a)):
        if i < len(a)-1:
            if a[i] > a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
                is_sorted = False
                swaps += 1
        
print("Array is sorted in {} swaps.".format(swaps))
print("First Element: {}".format(a[0]))
print("Last Element: {}".format(a[len(a)-1]))

##### 22st Solution
#---------------------------------------------------------------

#In this solution using C++ Langauge; 
# because No options choosing Python Langauge

# Go To 21_solution.cpp file 

##### 23st Solution
#---------------------------------------------------------------

class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
class Solution:
    def insert(self,root,data):
        if root==None:
            return Node(data)
        else:
            if data<=root.data:
                cur=self.insert(root.left,data)
                root.left=cur
            else:
                cur=self.insert(root.right,data)
                root.right=cur
        return root

    def getHeight(self,root):
        #Write your code here
        if root:
            leftDepth = self.getHeight(root.left)
            rightDepth = self.getHeight(root.right)

            if leftDepth > rightDepth:
                return leftDepth + 1
            else:
                return rightDepth + 1

        else:
            return -1

T=int(input())
myTree=Solution()
root=None
for i in range(T):
    data=int(input())
    root=myTree.insert(root,data)
height=myTree.getHeight(root)
print(height)       
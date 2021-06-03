##### 24th Solution
#----------------------------------------------------------
import sys

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

    def levelOrder(self,root):
        #Write your code here
        from collections import deque
        if root:
            queue = deque([root])
        while queue:
            node = queue.popleft()
            print(node.data, end=' ')
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

T=int(input())
myTree=Solution()
root=None
for i in range(T):
    data=int(input())
    root=myTree.insert(root,data)
myTree.levelOrder(root)


##### 25th Solution
#----------------------------------------------------------
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None 
class Solution: 
    def insert(self,head,data):
            p = Node(data)           
            if head==None:
                head=p
            elif head.next==None:
                head.next=p
            else:
                start=head
                while(start.next!=None):
                    start=start.next
                start.next=p
            return head  
    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next

    def removeDuplicates(self,head):
        #Write your code here
        if head==None:
            return head
        fptr = head.next
        sptr = head
        ha = {}
        while fptr != None:
            if sptr.data not in ha:
                ha[sptr.data] = True
            if fptr.data in ha:
                sptr.next = fptr.next
                fptr = fptr.next
                continue
            sptr = fptr
            fptr = fptr.next
        return head

mylist= Solution()
T=int(input())
head=None
for i in range(T):
    data=int(input())
    head=mylist.insert(head,data)    
head=mylist.removeDuplicates(head)
mylist.display(head); 


##### 26th Solution
#----------------------------------------------------------
from itertools import count, islice

n = int(input())
for i in range(n):
    x, prime = int(input()), True
    sq = int(x**0.5)-1
    if x<2: 
        prime = False
    else:
        for num in islice(count(2), sq):
            if not x%num:
                prime = False
    print("Prime") if prime else print("Not prime")



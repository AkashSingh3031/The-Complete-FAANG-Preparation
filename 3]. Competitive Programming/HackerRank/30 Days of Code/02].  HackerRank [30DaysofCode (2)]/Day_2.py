# 4th Solution

N = int(input())

if N%2==1 or (N>3 and N<21):
    print("Weird")
else:
    print("Not Weird")
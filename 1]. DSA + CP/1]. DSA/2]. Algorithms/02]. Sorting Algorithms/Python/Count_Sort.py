#counting sort algorithm for positive numbers

def countsort(lst):
    n = len(lst)
    ans = [0]*(n)
    for i in range(n):
        ans[lst[i]] += 1

    for i in range(n):
        while(ans[i]>0):
            print(i, end = ' ')
            ans[i] -= 1

lst = [2,1,2,2,1,3,4,0,1,3]
countsort(lst)
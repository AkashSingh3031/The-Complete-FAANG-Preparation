if __name__ == '__main__':
    k = int(input())
    f={}
    l = list(map(int, input().split()))
    for i in l:
        if i in f:
            f[i]+=1
        else:
            f[i]=1
    for i in f:
        if f[i]==1:
            print(i)
            break 

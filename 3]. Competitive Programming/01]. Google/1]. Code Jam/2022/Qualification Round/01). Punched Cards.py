def solve(r,c):
    r = int(r)
    c = int(c)
    for i in range (1,r*2 +2):
        for j in range (1,c*2 + 2):
            if((i==1 or i ==2) and (j == 1 or j == 2)):
                print('.', end ="")
            elif(i % 2 == 1 and j % 2 == 1):
                print('+', end ="")
            elif(i % 2 == 0 and j % 2 == 1):
                print('|', end ="")
            elif(i % 2 == 1 and j % 2 == 0):
                print('-', end ="")
            elif(i % 2 == 0 and j % 2 == 0):
                print('.', end ="")
        print( )

test_num = int(input())
r=[0] * test_num
c=[0] * test_num
for i in range (test_num):
    r[i],c[i] = input().split()
for i in range (0,len(r)):
    print("Case #"+ str(i+1)+":")
    solve(r[i],c[i])



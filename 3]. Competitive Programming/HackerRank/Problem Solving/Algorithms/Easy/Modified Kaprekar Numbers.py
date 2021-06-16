
# Contributed by Paraj Shah
# https://github.com/parajshah

count = 0
for i in range(int(input()),int(input()) + 1):
    s = str(i**2)
    x = s[len(s)//2:]
    y = s[0:len(s)//2]

    if x == '':
        x = 0
    if y == '':
        y = 0
    if int(x) + int(y) == i:
        print(i,end = ' ')
        count += 1
if count == 0:
    print("INVALID RANGE")

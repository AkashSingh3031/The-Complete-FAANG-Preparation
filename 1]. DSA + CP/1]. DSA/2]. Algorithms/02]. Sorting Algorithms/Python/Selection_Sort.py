a = [5, 4, 8, 3, 4, 14, 90, 45, 9, 3, 2, 4]
for i in range(0,len(a)-1):
    min = i
    for j in range(i+1,len(a)):
        if a[j]<a[min]:
            min = j
    a[i],a[min]=a[min],a[i]
print(a)
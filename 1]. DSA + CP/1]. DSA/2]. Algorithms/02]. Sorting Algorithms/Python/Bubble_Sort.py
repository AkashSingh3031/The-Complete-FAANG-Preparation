a = [5, 4, 8, 3, 4, 14, 90, 45, 9, 3, 2, 4]
for i in range(len(a), 0, -1):
    for j in range(0, i - 1):
        if a[j] > a[j + 1]:
            a[j], a[j + 1] = a[j + 1], a[j]
print(a) 
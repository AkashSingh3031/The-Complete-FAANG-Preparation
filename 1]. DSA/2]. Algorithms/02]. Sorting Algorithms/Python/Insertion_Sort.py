def sort(a):
    for j in range(1, len(a)):
        key = a[j]
        i = j - 1
        while i > -1 and a[i] > key:
            a[i + 1] = a[i]
            i = i - 1
        a[i + 1] = key
    return a

if __name__ == '__main__':
    a = [5, 4, 8, 3, 4, 14, 90, 45, 9, 3, 2, 4]
    print(sort(a))
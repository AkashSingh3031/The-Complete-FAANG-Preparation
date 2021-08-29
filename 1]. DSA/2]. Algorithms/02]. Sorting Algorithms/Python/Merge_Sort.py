def divide(arr):
    if len(arr)>1:
        a = arr[:len(arr)//2]
        b = arr[len(arr)//2:]
        divide(a)
        divide(b)
        i = j = k = 0
        while(i<len(a) and j<len(b)):
            if a[i]<b[j]:
                arr[k] = a[i]
                i+=1
            else:
                arr[k] = b[j]
                j+=1
            k+=1
        while i < len(a):
            arr[k] = a[i]
            i += 1
            k += 1
        while j < len(b):
            arr[k] = b[j]
            j += 1
            k += 1
    

arr = [5, 4, 8, 3, 4, 14, 90, 45, 9, 3, 2, 4]
divide(arr)
print(arr)
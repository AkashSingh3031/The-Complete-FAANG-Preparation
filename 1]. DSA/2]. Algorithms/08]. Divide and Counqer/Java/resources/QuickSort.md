# Quick Sort

[QuickSort Program](https://github.com/AkashSingh3031/The-Complete-FAANG-Preparation/blob/master/1%5D.%20DSA/2%5D.%20Algorithms/02%5D.%20Sorting%20Algorithms/Java/QuickSort.java)

- Quick Sort is another popular and widely-used Sorting Algorithm and is a well-suited example for Divide & Conquer Technique.
- Quick Sort approach divides it's input elements according to their value `(and not by according to their position as in case of Merge Sort)`.
- In particular Quick Sort algorithm/ technique rearranges elements of a given array `A[0...n-1]` to achieve its `partition`.

---

## Algorithm: `QuickSort (A[0...n-1])`

---

1.  Sorts a subarray by Quick Sort
2.  Input: A subarray `A[l....r]` of `A[0...n-1]` which is defined by its left and right indices(index) `l and r`.
3.  Output: A subarray `A[l...r]` sorted in an Ascending order.

        Pivot=A[0].. First element is pivot.
        i=l or 1.. left pointer.
        j=r or n-1.. right pointer.

---

        if l(left) < r(right)
        s<-partition(A[l...r]) // s is split position/pivot
        QuickSort(A[l...s-1])
        QuickSort(A[s+1...r])

        - PARTITION

        1. This Algorithm partitions (divides) a sub-array by using it's first element as pivot.
        2. Input: A sub-array A[l..r] of A[0...n-1] defined by its left and right indices(index) l and r (l<r).
        3. Output: A partition of A[l..r], with its split position i.e., a position for swap with pivot.

            pivot<-A[l]
            l<-l; j<-r+1

        ----<repeat
        |
        |    repeat i<-i+1 unitl A[i]>=pivot
        |    repeat j<-j-1 until A[j]<=pivot
        |    swap(A[i], A[j])
        |
        -----> until i>=j
           swap (A[i], A[j]) undo last swap when i>=j
           swap (A[l], A[j])
            return j

# Explanation

            Step 1 − Choose the highest index value has pivot.
            Step 2 − Take two variables to point left and right of the list excluding  pivot.
            Step 3 − left points to the low index.
            Step 4 − right points to the high.
            Step 5 − while value at left is less than pivot move right.
            Step 6 − while value at right is greater than pivot move left.
            Step 7 − if both step 5 and step 6 does not match swap left and right.
            Step 8 − if left ≥ right, the point where they met is new pivot.

## Read it Once Again...😅
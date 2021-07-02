# Sorting Algorithm Explainations

<details>
  <summary>
  <img id="sort" src="https://img.shields.io/badge/Merge-Sort-brightgreen?style=for-the-badge"></summary>
  <h1> Merge Sort</h1>

[MergeSort Program](https://github.com/AkashSingh3031/The-Complete-FAANG-Preparation/blob/master/1%5D.%20DSA/2%5D.%20Algorithms/02%5D.%20Sorting%20Algorithms/Java/MergeSort.java)

- It's One of the perfect example of a successful application of the Divide and Conquer Technique.
- It sorts the given array `A[0....n-1]` by Dividing it into two halves `A[0...(n/2)-1]` and `A[(n/2)....n-1]`.

## First let's write `MERGESORT`

# Algorithm: `MergeSort` `(A[0...n-1])`

> 1. Short array `A[0...n-1]` by recursive Merge Sort technique.
> 2. Input: An Array `A[0....n-1]` of orderable elements.
> 3. Output: Array `A[0....n-1]` sorted in Ascending order.

    if n>1
    Copy A[0.....(n/2)-1] to B[0...(n/2)-1].
    Copy A[(n-2)....n-1] to C[0....(n/2)-1].
    Mergesort (B[0...(n/2)-1])
    Mergesort (C[0...(n/2)-1])
    Megrge(B,C,A)

## Let's Crack It

- That's INPUT--> `B=[2,3,8,9]` and `C=[1,4,5,7]`

---

- Output --> `A=[1,2,3,4,5,6,7,8,9]`

          Merge ( B=[0...p-1] , C=[0...q-1], A[0...p+q-1] );

        in `A[0...p+q-1]` 0 is index of Array, which start with 0, and `p+q` are the array last index of `B` and `C` array's List.
                i<-0; j<-0; k<-0;
                    while i<p and j<q do
                        if B[i] <= C[j]
                            A[k] <-B[i]; i<-i+1
                        else A[k] <-C[j]; j<-j+1
                        k<-k+1
                        if i=p
                            copy C[j....q-1] to A[k...p+q-1]
                        else
                            copy B[i...p-1] to A[k...p+q-1]

# Explanation

            Step 1 − If it is only one element in the list it is already sorted, return.
            Step 2 − Divide the list recursively into two halves until it can no more be divided.
            Step 3 − Merge the smaller lists into new list in sorted order.

## Read it Once Again...😅

</details>

<details>
  <summary><img id="sort" src="https://img.shields.io/badge/Quick-Sort-brightgreen?style=for-the-badge">
  </summary>
  <h1>Quick Sort</h1>

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

</details>

<details>
  <summary><img id="sort" src="https://img.shields.io/badge/Binary-Sort-brightgreen?style=for-the-badge"></summary>

  <h1> Binary Search</h1>

[BinarySearch Program](https://github.com/AkashSingh3031/The-Complete-FAANG-Preparation/blob/master/1%5D.%20DSA/2%5D.%20Algorithms/01%5D.%20Searching%20Algorithms/Java/BinarSearch.java)

- Binary Search is a faster-search algorithm and efficient for searching in a `sorted array`. Thats's `Binary search works on ordered lits only!`.
- The Algorithm works by comparing a search key `K` with the array's middle element `A[mid]`. (i.e., if `K==A[mid]`).
- If they match, The algorithm stops. Otherwise, the same operation is repeated recursively for the first-half of the array, if `K<A[mid]` and for the second-half if `K>A[mid]`.
- Thus, if the comparison results is True (matches) then it's position `(mid)` is returned. Otherwise, the Search continues either in the `left-half` or in the `right-half` depending upon the value of the key `K`.

# Algorithm: `Binary Search (A[0...n-1], K`

1.  This is a non-Recursive Binary Search Algorithm.
2.  Input: An Array `A[0...n-1]` sorted in Ascending order and a search key `K`.
3.  Output: An index of the array's element position matching `K`. or `-1` if there is no matching element.

                l=left index(0)
                r=right index(n-1)
                mid=medium (array's index divided into 2 equal parts.. that's mid)


            l<--0; r<-(n-1);
        ---<while l<r do
        |    mid<-[l+r]/2
        |   if K=A[mid] return mid
        |       else if K<A[mid] r<-mid-1
        -----else l<-mid+1;
            return -1;

# Explanation

        Step 1 − Take Array's Element as Input and A Search key Called K.
        Step 2 − Left points to the low index.
        Step 3 − Right points to the high.
        Step 4 − While Left is smaller then Right.
        Step 5 - Add Left and Right Indices(Index) and Divide it by 2 (mid=(l+r)/2) and assign the value to MID.
        Step 6 − Match the K element with the MID if This is True (matches), Then return the element with mid.
        Step 7 − If the K element is smaller then MID element. Then, assign the R element with MID-1 (K<A[mid]..r=mid-1).
        Step 8 − OtherWise assing the value of l with adding the MID+1.
        Step 9 - If Not Match any Cases... Return with -1.

## Read it Once Again...😅

  
</details>

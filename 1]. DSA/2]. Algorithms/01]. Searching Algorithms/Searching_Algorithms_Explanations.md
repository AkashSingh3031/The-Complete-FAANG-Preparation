# Sorting Algorithm Explainations

<details>
  <summary><img id="search" src="https://img.shields.io/badge/Binary-Search-brightgreen?style=for-the-badge"></summary>

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

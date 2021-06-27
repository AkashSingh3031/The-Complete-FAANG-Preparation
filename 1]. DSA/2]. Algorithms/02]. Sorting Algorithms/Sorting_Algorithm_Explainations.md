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

## Read it Once Again...😅

</details>

<details>
  <summary><img id="sort" src="https://img.shields.io/badge/Quick-Sort-brightgreen?style=for-the-badge"></summary>
  
</details>

<details>
  <summary><img id="sort" src="https://img.shields.io/badge/Insertion-Sort-brightgreen?style=for-the-badge"></summary>
  
</details>

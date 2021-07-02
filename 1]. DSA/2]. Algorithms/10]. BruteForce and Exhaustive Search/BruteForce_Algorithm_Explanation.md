<h1>Silent Features of Brute Force Approach</h1>

---

1. It is applicable to wide-variety of problems.

2. For Problems such as Sorting, Searching, String Matching,
   Matrix Muliplication. The Brute Force approach yields/gives
   us some reasonable algorithms of atleast some practical
   values with no limitations on instance size(n).

3. Even if too insufficient in general. A Brute force algorithm
   can still be useful for solving small-size instances of a problem.

4. Brute-Force algorithm can serve as an important theoretical
   or educational purpose. That is it serve as basis with which
   other efficient alternative algorithms can be considered
   (and/or Compared) for solving a given problem.

<details>
    <summary>
        <img id="sort" src="https://img.shields.io/badge/Selection-Sort-brightgreen?style=for-the-badge">
    </summary>
  <h1>Selection Sort</h1>

# SelectionSort Algorithm `(A[0...n-1], n)`

- Arranges element of given array into Ascending order b selection Sort.
- Input: An Array of `A[0...n-1]` of `n` element in unsorted order.
- Output: Array of `A[0...n-1]` sorted in Ascending order.

          for i<-0 to n-2 do
          min <-i
          for j<-(i+1) to (n-1) do // This loop is to find the Smallest
          element in the array.
          if A[j]<A[min] // true then
          min<-j //Position of Smallest element
          swap A[i] and A[min]
          temp<-A[i]
          A[i]<-A[min]
          A[min]<-temp

---

# Explanation

- In the Given Array `A[0...n-1]`, we start selection sort by scanning the entire array to find the smallest element and exchange it with the first elemnt i.e., `A[0]` keeping the smallest element in its final position in the sorted list.
- Further scan the array starting with the second element and find the smallest among the last `n-1` elements and exchange it with the second element i.e., `A[1]`, Keeping the second smallest element in it's final position in the sorted list.
- Like wise in each iteration, the unsorted array size minimises and partially sorted list increates. Therefore the name `Selection Sort` i.e., `Selecting The Smallest Element`.

  </details>

<details>
    <summary>
        <img id="sort" src="https://img.shields.io/badge/Bubble-Sort-brightgreen?style=for-the-badge">
    </summary>
  <h1>Bubble Sort</h1>

# BubbleSort Algorithm `(A[0...n-1])`

- Sorts a given array using Bubble Sort technique.
- Input: An Array of `A[0...n-1]` of `n` element.
- Output: Array of `A[0...n-1]` sorted in Ascending order.

          for i<-0 to n-2 do
            for j<-0 to n-2-i do.
               if A[j]>A[j+1] // true then
                  // swap A[j] <-> A[j+1]
               temp<-A[j]
               A[j]<-A[j+1]
               A[j+1]<-temp

---

# Explanation

- This algorithm compares adjacent elements of an array and swaps them if the element on the right is smaller than the one on the left`A[j]>A[j+1]`, then It Start Swaping. It is an in-place sorting algorithm i.e. no extra space is needed for this sort, the array itself is modified.

## It's Easy

  </details>

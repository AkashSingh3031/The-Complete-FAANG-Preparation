#
#Objective
#Today, we are learning about an algorithmic concept called recursion. Check out the Tutorial tab for learning materials and an instructional video.
#
#Recursive Method for Calculating Factorial
#  factorial(N) = N * factorial (N-1)
#
#
#Function Description
#Complete the factorial function in the editor below. Be sure to use recursion.
#
#factorial has the following paramter:
#
#int n: an integer
#
#Returns
#
#int: the factorial of n
#Note: If you fail to use recursion or fail to name your recursive function factorial or Factorial, you will get a score of 0.
#
#Input Format
#
#A single integer, n (the argument to pass to factorial).
#
#Sample Input
#
#3
#
#Sample Output
#
#6
#
#Explanation
#
#Consider the following steps. After the recursive calls from step 1 to 3, results are accumulated from step 3 to 1.
#  factorial(3) = 3 x factorial(2) = 3 x 2 = 6
#
#

#!/bin/bash
function factorial
(
    read n
    mltply=1
    i=1
    while [[ i -le $n ]]
    do
        mltply=$(($mltply * i))
        i=$(($i + 1))
    done
    echo $mltply
)
factorial
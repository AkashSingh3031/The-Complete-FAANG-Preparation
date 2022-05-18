/*
#####Objective#####
Today, we're learning about the Array data structure. Check out the Tutorial tab for learning materials and an instructional video!

#####Task#####
Given an array, A, of N integers, print A's elements in reverse order as a single line of space-separated numbers.

#####Input Format#####

The first line contains an integer, N (the size of our array).
The second line contains N space-separated integers describing array A's elements.

#####Constraints#####

1 <= N <= 1000
1 <= A(i) <=10000 ; where A(i) is the ith integer in the array.

#####Output Format#####

Print the elements of array A in reverse order as a single line of space-separated numbers.

#####Sample Input#####
4
1 4 3 2

#####Sample Output#####
2 3 4 1

*/

// SCALA CODE

import java.io._
import java.math._
import java.security._
import java.text._
import java.util._
import java.util.concurrent._
import java.util.function._
import java.util.regex._
import java.util.stream._

object Solution {

    def main(args: Array[String]) {
        val stdin = scala.io.StdIn

        val n = stdin.readLine.trim.toInt

        val arr = stdin.readLine.split(" ").map(_.trim.toInt)

        val rev_arr = arr.reverse

        rev_arr.foreach(x => print(x+" "))

    }
}



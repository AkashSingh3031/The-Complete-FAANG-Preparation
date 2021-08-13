/*
#####Objective#####
In this challenge, we're going to use loops to help us do some simple math. Check out the Tutorial tab to learn more.

#####Task#####
Given an integer, n, print its first 10 multiples. Each multiple n x i (where 1 <= n <= 10) should be printed on a new line in the form: n x i = result.

#####Input Format#####

A single integer, n.

#####Constraints#####

2 <= n <= 20

#####Output Format#####

Print 10 lines of output; each line i (where 1 <= i <= 10) contains the result of n x i in the form:
n x i = result.

#####Sample Input#####
2


#####Sample Output#####
2 x 1 = 2
2 x 2 = 4
2 x 3 = 6
2 x 4 = 8
2 x 5 = 10
2 x 6 = 12
2 x 7 = 14
2 x 8 = 16
2 x 9 = 18
2 x 10 = 20

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

        for ( i <- 1 to 10)
            println(s"$n x $i = " + n*i)
    }
}

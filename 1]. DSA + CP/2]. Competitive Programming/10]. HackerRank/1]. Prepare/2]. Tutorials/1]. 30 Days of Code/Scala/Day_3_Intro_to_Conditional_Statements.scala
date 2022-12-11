/*
#####Objective#####
In this challenge, we're getting started with conditional statements. Check out the Tutorial tab for learning materials and an instructional video!

#####Task#####
Given an integer, , perform the following conditional actions:

If n is odd, print Weird
If n is even and in the inclusive range of 2 to 5, print Not Weird
If n is even and in the inclusive range of 6 to 20, print Weird
If n is even and greater than 20, print Not Weird

Complete the stub code provided in your editor to print whether or not  is weird.

#####Input Format#####

A single line containing a positive integer, .

#####Constraints#####

1 <= n <= 100

#####Output Format#####

Print Weird if the number is weird; otherwise, print Not Weird.

#####Sample Input 0#####
3
#####Sample Output 0#####
Weird

#####Sample Input 1#####
24
#####Sample Output 1#####
Not Weird


#####Explanation#####

Sample Case 0: n = 3
n is odd and odd numbers are weird, so we print Weird.

Sample Case 1: n = 24
n > 20 and n is even, so it isn't weird. Thus, we print Not Weird.

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

        val N = stdin.readLine.trim.toInt

        if ( N%2 == 0 ){
            if ( N>=2 && N<=5 ) println("Not Weird")
            else if ( N>=6 && N<=20 ) println ("Weird")
            else if ( N>20 ) println ("Not Weird")
        }
        else println ("Weird")
    }
}

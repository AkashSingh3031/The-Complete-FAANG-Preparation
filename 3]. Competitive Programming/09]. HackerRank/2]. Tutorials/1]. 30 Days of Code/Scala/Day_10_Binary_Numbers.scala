/*
Objective
Today, we're working with binary numbers. Check out the Tutorial tab for learning materials and an instructional video!

Task
Given a base-10 integer, n, convert it to binary (base-2). Then find and print the base-10 integer denoting the maximum number of consecutive 1's in n's binary representation. When working with different bases, it is common to show the base as a subscript.

Example
n = 125

The binary representation of 125 base-10 is 1111101 base-2. In base 10, there are 5 and 1 consecutive ones in two groups. Print the maximum, 5.

Input Format

A single integer, n.

Output Format

Print a single base-10 integer that denotes the maximum number of consecutive 1's in the binary representation of n.

Sample Input 1

5

Sample Output 1

1

Sample Input 2

13

Sample Output 2

2

Explanation

Sample Case 1:
The binary representation of 5 base-10 is 101 base-2 , so the maximum number of consecutive 1's is 1.

Sample Case 2:
The binary representation of 13 base-10 is 1101 base-2, so the maximum number of consecutive 1's is 2.
*/

//(Scala Solution)

import java.io._
import java.math._
import java.security._
import java.text._
import java.util._
import java.util.concurrent._
import java.util.function._
import java.util.regex._
import java.util.stream._
import scala.collection.immutable._
import scala.collection.mutable._
import scala.collection.concurrent._
import scala.concurrent._
import scala.io._
import scala.io.StdIn._
import scala.math._
import scala.sys._
import scala.util.matching._
import scala.reflect._

object Solution {
    def main(args: Array[String]) {
        val n = readLine.trim.toInt
        //println(n.toBinaryString)
        print(n.toBinaryString.split("0").map(_.length).max)
    }
}
/*
#####Objective#####
In this challenge, you'll work with arithmetic operators. Check out the Tutorial tab for learning materials and an instructional video!

#####Task#####
Given the meal price (base cost of a meal), tip percent (the percentage of the meal price being added as tip), and tax percent (the percentage of the meal price being added as tax) for a meal, find and print the meal's total cost.

	Note: Be sure to use precise values for your calculations, or you may end up with an incorrectly rounded result!

#####Input Format#####

There are  lines of numeric input:
The first line has a double,  (the cost of the meal before tax and tip).
The second line has an integer,  (the percentage of  being added as tip).
The third line has an integer,  (the percentage of  being added as tax).

#####Output Format#####

Print the total meal cost, where  is the rounded integer result of the entire bill ( with added tax and tip).

#####Sample Input#####

12.00
20
8


#####Sample Output#####

15


#####Explanation#####

Given:
mealCost = 12, tipPercent = 20, taxPercent = 8

Calculations:

tip = 12 * 0.2 = 2.4
tax = 12 * 0.8 = 0.96
totalCost = mealCost + tip + tax = 12 + 2.4 + 0.96 = 15.36

round(totalCost) = 15

We round totalCost to the nearest dollar (integer) and then print our result,15.

*/

//SCALA CODE BELOW:

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

    // Complete the solve function below.
    def solve(meal_cost: Double, tip_percent: Int, tax_percent: Int) {
        
        println((meal_cost+((meal_cost*tip_percent)/100)+((meal_cost*tax_percent)/100)).round)

    }

    def main(args: Array[String]) {
        val stdin = scala.io.StdIn

        val meal_cost = stdin.readLine.trim.toDouble

        val tip_percent = stdin.readLine.trim.toInt

        val tax_percent = stdin.readLine.trim.toInt

        solve(meal_cost, tip_percent, tax_percent)
    }
}

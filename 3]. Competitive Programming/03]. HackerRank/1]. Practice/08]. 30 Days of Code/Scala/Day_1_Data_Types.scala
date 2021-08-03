/*
#####Objective#####
Today, we're discussing data types. Check out the Tutorial tab for learning materials and an instructional video!

#####Task#####
Complete the code in the editor below. The variables , , and  are already declared and initialized for you. You must:

1) 	Declare  variables: one of type int, one of type double, and one of type String.
2) 	Read  lines of input from stdin (according to the sequence given in the Input Format section below) and initialize your  variables.
3) 	Use the  operator to perform the following operations:
		a)	Print the sum of  plus your int variable on a new line.
		b)	Print the sum of  plus your double variable to a scale of one decimal place on a new line.
		c)	Concatenate  with the string you read as input and print the result on a new line.

	Note: If you are using a language that doesn't support using  for string concatenation (e.g.: C), you can just print one variable immediately following the other on the same line. The string provided in your editor must be printed first, immediately followed by the string you read as input.

#####Input Format#####

The first line contains an integer that you must sum with .
The second line contains a double that you must sum with .
The third line contains a string that you must concatenate with .

#####Output Format#####

Print the sum of both integers on the first line, the sum of both doubles (scaled to  decimal place) on the second line, and then the two concatenated strings on the third line.

#####Sample Input#####

12
4.0
is the best place to learn and practice coding!


#####Sample Output#####

16
8.0
HackerRank is the best place to learn and practice coding!


#####Explanation#####

When we sum the integers  and , we get the integer .
When we sum the floating-point numbers  and , we get .
When we concatenate HackerRank with is the best place to learn and practice coding!, we get HackerRank is the best place to learn and practice coding!.

**You will not pass this challenge if you attempt to assign the Sample Case values to your variables instead of following the instructions above and reading input from stdin.**

*/

//SCALA CODE BELOW:

object Solution {
    def main(args: Array[String]) {
        val i = 4
        val d = 4.0
        val s = "HackerRank "

		// Read values of another integer, double, and string variables
        // Note use scala.io.StdIn to read from stdin

        val input_int = scala.io.StdIn.readInt
        val input_double = scala.io.StdIn.readDouble
        val input_string = scala.io.StdIn.readLine
        
        // Print the sum of both the integer variables
        
        println(i+input_int)

        // Print the sum of both the double variables
        println(d+input_double)
        // Concatenate and print the string variables
        // The 's' variable above should be printed first.
        println(s+input_string)
    }
}
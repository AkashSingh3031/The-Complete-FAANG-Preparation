/*
Objective
Today, we're learning about Key-Value pair mappings using a Map or Dictionary data structure. Check out the Tutorial tab for learning materials and an instructional video!

Task
Given n names and phone numbers, assemble a phone book that maps friends' names to their respective phone numbers. You will then be given an unknown number of names to query your phone book for. For each name queried, print the associated entry from your phone book on a new line in the form name=phoneNumber; if an entry for name is not found, print Not found instead.

Note: Your phone book should be a Dictionary/Map/HashMap data structure.

Input Format

The first line contains an integer, n, denoting the number of entries in the phone book.
Each of the n subsequent lines describes an entry in the form of 2 space-separated values on a single line. The first value is a friend's name, and the second value is an 8-digit phone number.

After the n lines of phone book entries, there are an unknown number of lines of queries. Each line (query) contains a name to look up, and you must continue reading lines until there is no more input.

Note: Names consist of lowercase English alphabetic letters and are first names only.

Output Format

On a new line for each query, print Not found if the name has no corresponding entry in the phone book; otherwise, print the full name and phonenumber in the format name=phoneNumber.

Sample Input

3
sam 99912222
tom 11122222
harry 12299933
sam
edward
harry

Sample Output

sam=99912222
Not found
harry=12299933
Explanation

We add the following n=3 (Key,Value) pairs to our map so it looks like this:
phoneBook={(sam,99912222),(tom,11122222),(harry,12299933)}

We then process each query and print key=value if the queried key is found in the map; otherwise, we print Not found.

Query 0: sam
Sam is one of the keys in our dictionary, so we print sam=99912222.

Query 1: edward
Edward is not one of the keys in our dictionary, so we print Not found.

Query 2: harry
Harry is one of the keys in our dictionary, so we print harry=12299933.

*/

import scala.collection.mutable
import scala.io.StdIn
    
object Solution {

    def main(args: Array[String]) {
    
        val sc = new java.util.Scanner(System.in)
        val n = sc.nextLine.toInt
        val book = mutable.HashMap[String, String]()
        for (i <- 0 until n) {
          val split = sc.nextLine.split(" ")
          book.put(split(0), split(1))
        }

        while (sc.hasNext) {
            val query = sc.nextLine
            val nr = book.get(query)
            if (nr.isDefined) {
                println(query+"="+nr.get)
            } else {
                println("Not found")
            }
            //query = sc.nextLine
        }
    }
}

#
#Objective
#Today, we're working with binary numbers. Check out the Tutorial tab for learning materials and an instructional video!
#
#Task
#Given a base-10 integer, n, convert it to binary (base-2). Then find and print the base-10 integer denoting the maximum number of consecutive 1's in n's binary representation. When working with different bases, it is common to show the base as a subscript.
#
#Example
#n = 125
#
#The binary representation of 125 base-10 is 1111101 base-2. In base 10, there are 5 and 1 consecutive ones in two groups. Print the maximum, 5.
#
#Input Format
#
#A single integer, n.
#
#Output Format
#
#Print a single base-10 integer that denotes the maximum number of consecutive 1's in the binary representation of n.
#
#Sample Input 1
#
#5
#
#Sample Output 1
#
#1
#
#Sample Input 2
#
#13
#
#Sample Output 2
#
#2
#
#Explanation
#
#Sample Case 1:
#The binary representation of 5 base-10 is 101 base-2 , so the maximum number of consecutive 1's is 1.
#
#Sample Case 2:
#The binary representation of 13 base-10 is 1101 base-2, so the maximum number of consecutive 1's is 2.
#

#(Bash Solution)

#!/bin/bash

declare -i INPUT1 OUTPUT1 STRLENG MAX

read INPUT1
BINARYNUM=$(echo "obase=2;$INPUT1" | bc)
STRLENG=${#BINARYNUM}

MAX=0
COUNT=0

for ((i=0; i < STRLENG; i++)); do
	if ((${BINARYNUM:$i:1} == 0)); then
		if ((COUNT>MAX)); then
			MAX=COUNT		
		fi
		COUNT=0
	else
	   ((COUNT++))
	fi
done
    if ((COUNT>MAX)); then
		MAX=COUNT
		COUNT=0
    fi
echo $MAX
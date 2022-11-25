/*
    Time complexity: O(1)
    Space complexity: O(1).
*/

#include <utility>

pair < int, int > swap(pair < int, int > swapValues) {

    /* 
        Store the sum of the 2 variables in 'a'.
        Considering 'a' as first value and 'b' as second value of pair.
    */
    swapValues.first = swapValues.first + swapValues.second;

    // The differnce between 'a' and 'b' is equal to 'b'.
    swapValues.second = swapValues.first - swapValues.second;

    // The difference between 'a' and 'b' is 'a'.
    swapValues.first = swapValues.first - swapValues.second;
    
    return swapValues;

}

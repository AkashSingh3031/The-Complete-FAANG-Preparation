// Search a 2D Matrix
// Link : https://leetcode.com/problems/search-a-2d-matrix/

// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

//Using binary_search STL
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(auto i : matrix) 
            if(binary_search(i.begin(),i.end(),target))
               return true;
            return false;
    }
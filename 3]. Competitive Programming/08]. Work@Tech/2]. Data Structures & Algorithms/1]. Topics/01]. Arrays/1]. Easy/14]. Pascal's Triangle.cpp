/*
Sample Input
    3           // Test Case Number
    4
    5
    6
Expected Output
    1 3 3 1
    1 4 6 4 1
    1 5 10 10 5 1
*/

vector<int> pascalTriangleRow(int rowNo) {
   	vector<int> pascalRow;
   	pascalRow.push_back(1);
   	rowNo--;

   	for (int i = 1; i <= rowNo; i++) {
       	int rowElement = pascalRow.back() * (rowNo - i + 1) / i;
       	pascalRow.push_back(rowElement);
   	}
       
   	return pascalRow;
}
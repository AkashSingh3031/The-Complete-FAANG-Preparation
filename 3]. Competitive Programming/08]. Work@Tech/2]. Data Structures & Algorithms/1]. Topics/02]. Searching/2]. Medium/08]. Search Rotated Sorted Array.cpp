/*
Example:
    List: [4, 5, 6, 7, 1, 2, 3]
    Target value: 6
    
    Resultant index: 2
*/

int getElementIndex(vector<int> &array, int target) {
    // add your logic here
	int l = 0, h = array.size()-1;
	while(l < h) {
		int m = (l+h)/2;
		if((array[0] > target) ^ (array[0] > array[m]) ^ (target > array[m]))
			l = m+1;
		else 
			h = m;
	}
	return l==h && array[l]==target ? l : -1;
}
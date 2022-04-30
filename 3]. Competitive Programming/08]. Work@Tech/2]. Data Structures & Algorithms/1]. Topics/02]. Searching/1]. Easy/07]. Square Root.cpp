/*
Exampl-1:
    n: 16
    Answer: 4

Exampl-2:
    n: 12
    Answer: 3
    
Exampl-3:
    n: 0
    Answer: 0
*/

int searchRoot(int num) {
    // add your logic here
	if (num == 0 || num == 1) {
       return num;
   	}
       
   	int low = 1, high = num, mid, ans = 1;
   	while (low <= high) {
       	mid = (high + low) / 2;
       	if (mid <= num / mid) {
           	low = mid + 1;
           	ans = mid;
       	} 
		else {
           	high = mid - 1;
       	}
   	}
   	return ans;
}
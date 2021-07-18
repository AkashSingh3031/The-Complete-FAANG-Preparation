	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    sort(arr,arr+n);
	    int i=0;
	    int j=n-1;
	  while(i<j)
	   {
	       if(arr[i]+arr[j]==x)
	       {
	           return 1;
	       }
	       else if(arr[i]+arr[j]<x)
	       {
	           i++;
	       }
	       else
	       {
	           j--;
	       }
	   }
	    return 0;
	    
	}
	
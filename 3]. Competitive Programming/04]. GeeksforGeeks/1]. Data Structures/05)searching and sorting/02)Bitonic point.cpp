	int findMaximum(int a[], int n) {
	    // code here
	    int l=0;
	    int h=n-1;
	    while(l<=h)
	    {
	        int mid=l+(h-l)/2;
	        
	        if(mid>0 && a[mid]>a[mid-1] && a[mid]>a[mid+1] || mid<n-1 && a[mid]>a[mid-1] && a[mid]>a[mid+1])
	        {
	            return a[mid];
	        }
	      
	        if(a[mid]<a[mid+1])
	        {
	            l=mid+1;
	        }
	        if(a[mid]<a[mid-1])
	        {
	            h=mid-1;
	        }
	        
	    }
	}
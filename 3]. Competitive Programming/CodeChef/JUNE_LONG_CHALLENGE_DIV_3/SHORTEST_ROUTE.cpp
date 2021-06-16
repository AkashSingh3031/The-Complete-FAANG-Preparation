
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
	    int n,m;
	    scanf("%d%d",&n,&m);
	    int a[n];
	    int l[n];
	    int r[n];
	    int temposl=-1;
	    int temposr=-1;
	    int posl[n];
	    int posr[n];
	    int templ=INT_MAX;
	    int tempr = INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	       scanf("%d",&a[i]);
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]!=0){
	            if(a[i]<=templ)
	            {
	                templ=a[i];
	                l[i]=templ;
	                temposl =i;
	                posl[i]=temposl;
	            }
	             else{
	            l[i]=templ;
	            posl[i]=temposl;
	        }
	        }
	        else{
	            l[i]=templ;
	            posl[i]=temposl;
	        }
	    }
	   // for(int i =0;i<n;i++)
	   // {
	   //     cout<<l[i]<<" ";
	   // }
	   // cout<<endl;
	   //  for(int i =0;i<n;i++)
	   // {
	   //     cout<<posl[i]<<" ";
	   // }
	   //  cout<<endl;

	    
	    
	    for(int i=n-1;i>=0;i--){
	        if(a[i]!=0){
	            if(a[i]>=tempr)
	            {
	                tempr=a[i];
	                r[i]=tempr;
	                temposr=i;
	                posr[i]=temposr;
	            }
	              else{
	            r[i]=tempr;
	            posr[i]=temposr;
	        }
	        }
	        else{
	            r[i]=tempr;
	            posr[i]=temposr;
	        }
	    }
	  
	   //	     for(int i =0;i<n;i++)
	   // {
	   //     cout<<r[i]<<" ";
	   // }
	   //  cout<<endl;
	   //  for(int i =0;i<n;i++)
	   // {
	   //     cout<<posr[i]<<" ";
	   // }
	   //  cout<<endl;
	
	
	    for(int i=0;i<m;i++)
	    {
	        int q;
	        scanf("%d",&q);
	        q=q-1;
if(q==0)
{
printf("%d ",0);
continue;
}
	        if(a[q]!=0)
	       { printf("%d ",0);}
	       else{
	        int left = l[q];
	        int right = r[q];
	        if(left==1&&right==2)
	        {
	           printf("%d ",min(q-posl[q],posr[q]-q));
	        }
	        else if(left==1&&right!=2){
	    printf("%d ",(q-posl[q]));
	        }
	        else if(right==2&&left!=1){
	           printf("%d ",(posr[q]-q));
	        }
	        else
	     
	        printf("%d ",-1);
	       }
	    }
	   printf("\n");
	}
	return 0;
}
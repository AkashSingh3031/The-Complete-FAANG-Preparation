void sort012(int a[], int n)
    {
        // coode here 
         int i,counto=0,countz=0,countt=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            countz++;
        }
        else if(a[i]==1)
        {
            counto++;
        }else if(a[i]==2)
        {
            countt++;
        }
       
       
    }
    i=0;
    while(countz>0)
    {
        a[i++]=0;
        countz--;
    }
     while(counto>0)
    {
        a[i++]=1;
        counto--;
    }
     while(countt>0)
    {
        a[i++]=2;
        countt--;
    }
   
    }
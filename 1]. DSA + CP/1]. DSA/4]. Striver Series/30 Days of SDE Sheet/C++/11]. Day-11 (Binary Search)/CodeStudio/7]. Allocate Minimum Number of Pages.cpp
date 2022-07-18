bool isPossible(int n, int m, vector<int> time,long long int mid){
   int dayCount = 1;
   long long int timeSum = 0;
   for(int i=0;i<m;i++){
       if(timeSum+time[i]<=mid){
           timeSum+=time[i];
       }else{
           dayCount++;
           if(dayCount>n || time[i]>mid){
               return false;
           }
           timeSum=time[i];
       }
   }
   return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) {  
   // Write your code here.
   long long int s=0;
   long long int sum=0;
   long long int ans=-1;
   for (int i=0;i<m;i++){
       sum+=time[i];
   }
   long long int e = sum;
   long long int mid = s + (e-s)/2;
   while(s<=e){
       if(isPossible(n,m,time,mid)){
           e=mid-1;
           ans=mid;
       }else{
           s=mid+1;
       }
       mid = s + (e-s)/2;
   }
   return ans;
}
bool good(vector<int> A, int m, int mid){
    if(A[0]>mid){
        return false;
    }
    int n = A.size();
    int cnt = 1, s = A[0];
    for(int i = 1;i<n;i++){
        if(A[i]>mid){
            return false;
        }
        if((A[i]+s)<=mid){
            s+=A[i];
        }
        else{
            s = A[i];
            cnt++;
        }
    }
    if(cnt>m){
        return false;
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    if(A.size()<B){
        return -1;
    }
    int sum = 0, ans = -1;
    for(int i = 0;i<A.size();i++){
        sum+=A[i];
    }
    int low = 0, high = sum;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(good(A, B, mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
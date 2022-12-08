void func(int index,int sum,vector<int>arr,vector<int> &sumOfSubsets){
    
    if(index==arr.size()){
        sumOfSubsets.push_back(sum);
        return;
    }
    func(index+1,sum+arr[index],arr,sumOfSubsets);
    func(index+1,sum,arr,sumOfSubsets);
}

vector<int> subsetSum(vector<int> &arr)
{
    // Write your code here
    vector<int>sumOfSubsets;
    func(0,0,arr,sumOfSubsets);
    sort(sumOfSubsets.begin(),sumOfSubsets.end());
    return sumOfSubsets;
}
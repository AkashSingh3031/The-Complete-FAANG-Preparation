int atoi(string str) {
    // Write your code here.
    int sign=1;
    int i=0;
    int ans=0;
    if(str[i]=='-'){
        sign=-1;
        i++;
    }
    for(;i<str.length();i++){
        if(str[i]-'0'>=0 && str[i]-'0'<=9){
            ans=ans*10+str[i]-'0';
        }
    }
    return ans*sign;
}

int strStr(string a, string b){
	//Write your code here
    if(b.find(a)<b.size())
        return b.find(a);
    else
        return -1;
}
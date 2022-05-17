#include <iostream>
using namespace std;

int fun(int n)
{
	if(n < 10)
		return n;
	return fun(n / 10) + n % 10;
}

int main()
{
	cout<<"Sum of Digits = "<<fun(253)<<endl;
	return 0;
}

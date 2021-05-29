#include <iostream>
using namespace std;

int jos(int n, int k)
{
	if(n == 1)
		return 0;
	else
		return (jos(n - 1, k) + k) % n;
}

int myJos(int n, int k)
{
	return jos(n, k) + 1;
}

int main()
{
	cout<<"Last Remain person index(start index at 1) after every 3rd person killed in 5 persons = "<<myJos(5, 3)<<endl;
	return 0;
}

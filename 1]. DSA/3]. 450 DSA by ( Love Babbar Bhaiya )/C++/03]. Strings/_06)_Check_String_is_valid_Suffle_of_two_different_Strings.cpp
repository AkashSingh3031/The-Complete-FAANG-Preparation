#include <iostream>
using namespace std;

void check_shuffle_of_2_string() 
{
    string a = "xy", b = "12";
    string s2 = "1xy2";
    int i = 0;
    int j = 0;
    for (auto& x : s2) 
    {
        if (i < a.size() && x == a[i])
            i++;

        else if (j < b.size() && x == b[j])
            j++;
    }
    if (s2.size() == i + j && i == a.size() && j == b.size()) 
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
}

int main() {
	check_shuffle_of_2_string();
	return 0;
}
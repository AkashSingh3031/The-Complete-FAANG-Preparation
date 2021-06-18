#include<cmath>
#include<iostream>
using namespace std;

int main(){
    int tipPercent, taxPercent;
    double mealCost;
    cin>>mealCost>>tipPercent>>taxPercent;

    double tax = mealCost*taxPercent/100;
    double tip = mealCost*tipPercent/100;

    cout<<round(mealCost+tax+tip);
    return 0;
}


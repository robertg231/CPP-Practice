#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    double mealPrice;
    cin >> mealPrice;

    double tipPercent;
    cin >> tipPercent;

    double taxPercent;
    cin >> taxPercent;

    double totalCost = mealPrice + (mealPrice * (tipPercent / 100)) +
                        (mealPrice * (taxPercent / 100));

    cout << "The total meal cost is " << round(totalCost) << " dollars.";


    return 0;
}

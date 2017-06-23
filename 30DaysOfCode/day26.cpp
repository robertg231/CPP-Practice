#include <iostream>

using namespace std;

int main()
{
    int dayReturn;
    int monthReturn;
    int yearReturn;

    int dayExpected;
    int monthExpected;
    int yearExpected;

    cin >> dayReturn >> monthReturn >> yearReturn;
    cin >> dayExpected >> monthExpected >> yearExpected;


    int fine = 0;

    if(yearReturn <= yearExpected)
    {
         if(yearReturn < yearExpected)
         {
             fine = 0;
         }
         else
         {
             //year is =
             if(monthReturn <= monthExpected)
             {
                 if(monthReturn < monthExpected)
                 {
                     fine = 0;
                 }
                 else
                 {
                     //month is =
                     if(dayReturn <= dayExpected)
                     {
                         fine = 0;
                     }
                     else
                     {
                         fine = 15 * (dayReturn - dayExpected);
                     }
                 }

             }
             else
             {
                 fine = 500 * (monthReturn - monthExpected);
             }
         }
    }
    else
    {
        //big fine
        fine = 10000;
    }

    cout << fine << endl;

    return 0;
}

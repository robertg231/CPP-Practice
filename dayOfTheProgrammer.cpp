#include<iostream>
#include<iomanip> //for padding zeros

using namespace std;

void find256th(int* monthDays, int& dd, int& mm);

int main()
{
    int year;
    cin >> year;

    //constraints
    //1700 <= y <= 2700

    //1700 - 1917 use Julian calendar
    //1919 - 2700 use Gregorian calendar
    //1918 ?? -Julian then switched to Gregorian
    //1918 - Julian(jan 1 - jan 31) - gregorian(feb 14 - ...)
    //So on 1918 Feb 14 was the 32nd day of the year

    //LEAP YEARS
    //Julian calendar- years % 4 == 0
    //Gregorian calendar- years % 400 == 0 and (years % 4 == 0 && !(years % 100))

    //Find the 256th day(aka day of the programmer) for the given year
    // print as dd.mm.yyyy

    //i might need this
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int day;
    int month;

    if(year < 1918)
    {
        //julian calendar

        if(year % 4 == 0)
        {
            //leap year
            months[1] = 29;
        }

        find256th(months, day, month);
    }
    else if(year > 1918)
    {
        //gregorian

        if( (year % 400 == 0) || ( (year % 4 == 0) && (year % 100 != 0) ) )
        {
            //leap year
            months[1] = 29;
        }

        find256th(months, day, month);
    }
    else
    {
        //julian -> gregorian
        //not a leap year for either

        //feb was cut
        months[1] = 15;

        find256th(months, day, month);
    }

    cout << setfill('0');
    cout << setw(2) << day << '.' << setw(2) << month << '.' << year;

    return 0;
}


void find256th(int* monthDays, int& dd, int& mm)
{
    dd = 0;
    mm = 0;
    for(int i = 0; i < 12; i++)
    {
        //setting day we are on
        dd += monthDays[i];
        //setting month we are on
        mm = i + 1;

        if(dd + monthDays[i + 1] > 256)
        {
            break;
        }
    }

    //so we ran out of whole months to add
    //so we find out how many more are needed to reach 256
    dd = 256 - dd;

    //if we need to add days then we are going into the next month
    if(dd != 0)
    {
        mm++;
    }
}

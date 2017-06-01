#include<iostream>
#include<cmath>
using namespace std;

int roundGrade(int grade);

int main()
{
    int size;
    
    cin >> size;
    
    int* grades = new int[size];
    
    for(int i = 0; i < size; i++)
    {
        cin >> grades[i];        
    }
    
    for(int i = 0; i < size; i++)
    {
        grades[i] = roundGrade(grades[i]);
        cout << grades[i] << endl;
    }

    return 0;
}


    //any grade <40 is failing
    //any grade <38 no rounding
    // grade - nexMult5 < 3 ROUND grade to next multof5

int roundGrade(int grade)
{
    if(grade < 38)
    {
        return grade;
    }
    
    //find next multiple of 5
    //roundUp(x/n) * n
    
    int mult5 = ceil(grade / 5.0) * 5;
    
    if(mult5 - grade < 3)
    {
        grade = mult5;
    }
    
    return grade;
  
}
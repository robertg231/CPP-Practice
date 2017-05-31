#include<iostream>
using namespace std;

class Person
{
private:
    int age;

public:
    Person();
    Person(int newAge);
    void yearPasses();
    void amIOld();
};

int main()
{
    int cases;
    cin >> cases;
    int age;

    for(int i = 0; i < cases; i++)
    {
        cin >> age;
        Person p(age);
        p.amIOld();
        for(int j = 0; j < 3; j++)
        {
            p.yearPasses();
        }
        p.amIOld();
        cout << endl;
    }

    return 0;
}

Person::Person()
{
    age = 0;
}

Person::Person(int newAge)
{
    if(newAge > -1)
    {
        age = newAge;
    }
    else
    {
        cout << "Age is not valid, setting age to 0." << endl;
        age = 0;
    }
}

void Person::yearPasses()
{
    age++;
}

void Person::amIOld()
{
    if(age < 13)
    {
        cout << "You are young.";
    }
    else if(age < 18)
    {
        cout << "You are a teenager.";
    }
    else
    {
        cout << "You are old.";
    }
    cout << endl;
}

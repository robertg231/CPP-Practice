#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person
{
protected:
    string firstName;
    string lastName;
    int id;
public:
    Person(string newFirstName = "", string newLastName = "", int newId = 0) :
        firstName(newFirstName), lastName(newLastName), id(newId)
        {}
    void printPerson();
};

void Person::printPerson()
{
    cout << "Name: " << lastName << ", " << firstName << endl
         << "ID: " << id << endl;
}

class Student: public Person
{
private:
    vector<int> scores;

public:
    Student(string newFirstName, string newLastName, int newId, vector<int> newScores):
        Person(newFirstName, newLastName, newId), scores(newScores)
        {}

    char calculate();
};

char Student::calculate()
{
    int avg = 0;
    for(int i = 0; i < scores.size(); i++)
    {
        avg += scores.at(i);
    }

    avg /= scores.size();

    if(avg >= 90)
    {
        return 'O';
    }
    else if(avg >= 80)
    {
        return 'E';
    }
    else if(avg >= 70)
    {
        return 'A';
    }
    else if(avg >= 55)
    {
        return 'P';
    }
    else if(avg >= 40)
    {
        return 'D';
    }
    else
    {
        return 'T';
    }
}


//main was provided. i just gotta make/finish the classes
int main()
{
    string fName;
    string lName;
    int id;
    int numScores;

    cin >> fName >> lName >> id >> numScores;
    vector<int> scores;

    for(int i = 0; i < numScores; i++)
    {
        int tmpScore;
        cin >> tmpScore;
        scores.push_back(tmpScore);
    }

    Student* s = new Student(fName, lName, id, scores);
    s->printPerson();
    cout << "Grade: " << s->calculate() << endl;

    return 0;
}

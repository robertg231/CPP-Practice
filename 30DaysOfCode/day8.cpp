#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    int size;
    cin >> size;

    unordered_map<string, int> phoneBook;

    string name;
    int phoneNumber;

    for(int i = 0; i < size; i++)
    {
        cin >> name >> phoneNumber;
        phoneBook.emplace(name, phoneNumber);
    }

    unordered_map<string, int>::iterator it;

    //clearing the \n left in the buffer by cin so getline doesn't get skipped
    //learned it somewhere on the internet among my 1000 tabs XD
    cin.ignore();
    while(getline(cin, name))
    {
        if(name.empty())
        {
            break;
        }
        it = phoneBook.find(name);
        if(it == phoneBook.end())
        {
            cout << "Not found" << endl;
            continue;
        }

        cout << name << '='  << it->second << endl;
    }




    return 0;
}

#include <iostream>
#include <regex>
#include <map>
#include <string>

using namespace std;

int main()
{

    multimap<string, string> table;

    int n;
    cin >> n;

    string name;
    string email;
    for(int i = 0; i < n; i++)
    {
        cin >> name >> email;
        table.insert(pair<string, string>(name, email));
    }

    regex gmailMatch (".+@gmail\\.com");

    for(map<string, string>::iterator i = table.begin(); i != table.end(); i++)
    {
        //cout << "i->second: " << i->second << endl;
        //cout << regex_match(i->second, gmailMatch);
        if(regex_match(i->second, gmailMatch))
        {
            cout << i->first << endl;
        }
    }

    return 0;
}

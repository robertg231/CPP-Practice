#include <bits/stdc++.h>
#include <string>

using namespace std;

int patternCount(string s){
    // Complete this function
    int patterns = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
        {
            while(s[++i] == '0')
            {
                //we got zeros
            }
            if(s[i] == '1')
            {
                if(s[i-1] == '0')
                {
                    patterns++;
                }
                i--;
            }
        }
    }
    return patterns;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = patternCount(s);
        cout << result << endl;
    }
    return 0;
}

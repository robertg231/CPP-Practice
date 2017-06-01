//given a 12hr AM/PM format convert to 24hr time
//hh:mm:ssAM or hh:mm:ssPM

//wouldn't compile on gitshell or cmder :((((
//but it did on hackerrank online compiler. i got the points :)
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string time;
    
    cin >> time;
    
    //cases to worry about....
    //12 am = 00:00:00 , 12 pm = 12:00:00 , and post 12 pm
    
    //sample input 07:05:45PM
    //      string 0123456789
    //sample output 07:05:45
    
    int hr = std::stoi(time.substr(0,2));
    
  
    if(time[8] == 'A')
    {
        //it's AM
        if(hr == 12)
        {
            //it's 12am so we set time to 00
            
            time[0] = '0';
            time[1] = '0';
        }
    }
    else
    {
        //it's PM
        
         if(hr < 12)
         {
             hr += 12;
         }
         
         time.replace(0,2, to_string(hr));
         
    }
    
    //removing AM or PM
    time.pop_back();
    time.pop_back();
    
    cout << time;
    
    return 0;
}
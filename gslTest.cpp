#include<iostream>
#include<gsl.h>
#include<boost/optional.hpp>

using namespace std;

int main()
{
    int x = 5;
    gsl::owner<int*> p = &x;
    boost::optional<string>;

    return 0;
}

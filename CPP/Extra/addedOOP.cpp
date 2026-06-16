#include<bits/stdc++.h>
using namespace std;

// ------------------------------------- Factory Pattern --------------------------------
// A factory pattern is a design pattern where you use a function (often static) to create and return objects instead of calling constructors directly.
class Number {
public:
    int x;
    static Number create(int value)
    {
        Number obj;
        obj.x = value;
        return obj;
    }
};

int main()
{
    Number n = Number::create(10);

    return 0;
}

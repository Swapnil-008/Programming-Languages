#include<iostream>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n)
    {
        int temp = n;
        int count = 0;
        while(temp > 0)
        {
            count++;
            temp /= 10;
        }
        int result = 0;
        temp = n;
        while(temp > 0)
        {
            result += power(temp % 10, count);
            temp /= 10;
        }
        return result == n;
    }
    int power(int base, int pow)
    {
        if(pow == 0)
        {
            return 1;
        }
        return base * power(base, pow-1);
    }
};
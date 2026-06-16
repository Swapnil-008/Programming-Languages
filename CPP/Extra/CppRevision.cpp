#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
    // vector<int> nums(5, 10);
    // for(int i = 0; i < 5; i++)
    // {
    //     cout<<i<<"  "<<(long long)&nums[i]<<endl;
    // }

    // int x = 10;
    // int *px = &x;
    // int **ppx = &px;
    // int ***pppx = &ppx;
    // cout<<(long long)&x<<"  "<<(long long)px<<endl;
    // cout<<(long long)&px<<"  "<<(long long)ppx<<endl;
    // cout<<(long long)&ppx<<"  "<<(long long)pppx<<endl;
    // cout<<(long long)&pppx<<"  ";


    // vector<int> vect(5);
    // for(int i = 0; i < 5; i++)
    // {
    //     cin>>vect[i];
    // }
    // for(int i = 0; i < 5; i++)
    // {
    //     cout<<vect[i]<<" ";
    // }

    // int num = 10;
    // int *p = &num;
    // cout<<(long long)p<<endl;
    // cout<<(long long)(p+1)<<endl;
    
    // int *temp = new int[5];
    // temp[0] = 10;
    // temp[1] = 15;
    // cout<<temp[0]<<" "<<temp[1]<<endl;
    // delete []temp;
    // temp = nullptr;
    // cout<<(long long)temp[0]<<" "<<(long long)temp[1]<<endl;
    

    //References
    // int x = 10;
    // int &y = x;
    // int &z = y;
    // cout<<x<<" "<<y<<" "<<z<<endl;

    // int num1 = 10;
    // int *pnum1 = &num1;
    // int *&ppnum1 = pnum1;
    // cout<<(long long)pnum1<<endl;
    // *pnum1 = 1000;
    // cout<<num1<<endl;
    // cout<<(long long)pnum1;

    //Goto is used to send the executer to label, it is a bad programming since it is an unconditional jump
    // int x = 1;
    // HELLO:
    //     cout<<x<<endl;
    //     x++;
    //     if(x <= 5)
    //     {
    //         goto HELLO;
    //     }
    //     cout<<"End of GoTo"<<endl;

    // char str1[50], str2[50];
    // cout<<str1<<endl;
    // cin.getline(str1, 50);
    // cin.getline(str2, 50);
    // if(strcmp(str1, str2) == 0)
    // {
    //     cout<<"Both strings are equal!"<<endl;
    // }
    // else if(strcmp(str1, str2) == 1)
    // {
    //     cout<<"String1 is greater than String2!"<<endl;
    // }
    // else{
    //     cout<<"String1 is lesser than String2!"<<endl;
    // }
    // cout<<str1<<" "<<str2<<endl;

    char *p = new char[50];
    strcpy(p, "HELLO");
    char *q = new char[strlen(p) + 1];
    strcpy(q, p);
    delete []p;
    cout<<q;
    
    return 0;
}
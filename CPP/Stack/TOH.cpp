#include<iostream>
using namespace std;
int count = 0;
void TOH(int n, char source, char destination, char intermediate)
{
    if(n == 0)
    {
        return;
    }
    TOH(n-1, source, intermediate, destination);
    cout<<source<<" --> "<<destination<<endl;
    count++;
    TOH(n-1, intermediate, destination, source);
}

int main()
{
    int n;
    cout<<"Enter No. of disks: ";
    cin>>n;
    TOH(n, 'S', 'D', 'I');
    cout<<"No. of transactions: "<<count<<endl;
    
    return 0;
}
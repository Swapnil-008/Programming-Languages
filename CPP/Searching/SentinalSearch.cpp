#include<iostream>
#include<vector>
using namespace std;

int sentinalSearch(vector<int>& vect, int target)
{
    int n = vect.size();
    int temp = vect[n-1];
    vect[n-1] = target;
    int i = 0;
    while(vect[i] != target)
    {
        i++;
    }
    if(i == n-1 && temp != target)
    {
        return 0;
    }
    if(i < n-1 || temp == target)
    {
        return 1;
    }
}

int main()
{
    int n;
    vector<int>vect;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    int val, target;
    for(int i = 0; i < n; i++)
    {
        cin>>val;
        vect.push_back(val);
    }
    cout<<"Enter target element: ";
    cin>>target;
    if(sentinalSearch(vect, target))
    {
        cout<<"Element "<<target<<" found!"<<endl;
    }
    else{
        cout<<"Element "<<target<<" not found!"<<endl;
    }
    return 0;
}
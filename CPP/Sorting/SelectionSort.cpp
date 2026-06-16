#include<iostream>
#include<vector>
#include<time.h>
// #include<climits>
#include<ctime>
using namespace std;

//Selection sort fixes the ith element in the ith iteration.

void selectionSort(vector<int>& vect)
{
    int n = vect.size();
    for(int i = 0; i <= n-2; i++)
    {
        for(int j = i+1; j <= n-1; j++)
        {
            if(vect[i] > vect[j])
            {
                swap(vect[i], vect[j]);
            }
        }
    }
}

int findMin(vector<int> vect, int ind)
{
    int min = vect[ind];
    int minInd = ind;
    for(int i = ind+1; i < vect.size(); i++)
    {
        if(vect[i] < min)
        {
            min = vect[i];
            minInd = i;
        }
    }
    return minInd;
}

void selectionSortModified(vector<int>& vect)
{
    int n = vect.size();
    for(int i = 0; i <= n-2; i++)
    {
        int ind = findMin(vect, i+1);
        if(vect[i] > vect[ind])
        {
            swap(vect[i], vect[ind]);
        }
    }
}

void printArray(vector<int> vect)
{
    for(int i = 0; i < vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> vect;
    // srand(time(0));
    for(int i = 0; i < 1000; i++)
    {
        vect.push_back(rand() % 1000);
    }
    // cout<<"Origingal Array: ";
    // printArray(vect);
    clock_t start = clock();
    selectionSortModified(vect);
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    // cout<<"Sorted Array: ";
    // printArray(vect);

    cout<<"Time taken for sorting the elements: "<<time_taken<<" seconds"<<endl;

    return 0;
}
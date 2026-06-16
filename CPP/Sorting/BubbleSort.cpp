#include<iostream>
#include<vector>
#include<time.h>
// #include<climits>
#include<ctime>
using namespace std;

//Bubble sort fixes the heavy elements at their position in each iteration and small elements come to the top of the list

void bubbleSort(vector<int>& vect)
{
    int n = vect.size();
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(vect[j] > vect[j+1])
            {
                swap(vect[j], vect[j+1]);
            }
        }
    }
}

//Adaptive sort doesn't execute the unnecessary iterations if the array is already sorted.

void bubbleSortAdaptive(vector<int>& vect)
{
    int n = vect.size();
    bool swapped = true;
    for(int i = 0; i < n-1 && swapped == true; i++)
    {
        swapped = false;
        for(int j = 0; j < n-i-1; j++)
        {
            if(vect[j] > vect[j+1])
            {
                swap(vect[j], vect[j+1]);
                swapped = true;
            }
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
    srand(time(0));
    for(int i = 0; i < 10000; i++)
    {
        vect.push_back(rand() % 100);
    }
    // cout<<"Origingal Array: ";
    // printArray(vect);
    clock_t start = clock();
    bubbleSortAdaptive(vect);
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    // cout<<"Sorted Array: ";
    // printArray(vect);

    cout<<"Time taken for sorting "<<vect.size()<<" elements: "<<time_taken<<" seconds"<<endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<climits>
#include<time.h>
using namespace std;

void merge(vector<int>& vect, int low, int mid, int high)
{
    vector<int>result;
    int i = low;
    int j = mid+1;
    while(i <= mid && j <= high)
    {
        if(vect[i] < vect[j])
        {
            result.push_back(vect[i]);
            i++;
        }
        else{
            result.push_back(vect[j]);
            j++;
        }
    }
    while(i <= mid)
    {
        result.push_back(vect[i]);
        i++;
    }
    while(j <= high)
    {
        result.push_back(vect[j]);
        j++;
    }
    i = 0;
    for(int k = low; k <= high; k++)
    {
        vect[k] = result[i];
        i++;
    }
}

void mergeSort(vector<int>& vect, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(vect, low, mid);
        mergeSort(vect, mid+1, high);
        merge(vect, low, mid, high);
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
    srand(time(NULL));
    for(int i = 0; i < 100 ; i++)
    {
        vect.push_back(rand() % 1000);
    }

    cout<<"Origingal Array: ";
    printArray(vect);
    clock_t start = clock();
    mergeSort(vect, 0, vect.size()-1);
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout<<"Sorted Array: ";
    printArray(vect);

    cout<<"Time taken for sorting the elements: "<<time_taken<<" seconds"<<endl;
    return 0;
}
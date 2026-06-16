#include<iostream>
#include<vector>
#include<climits>
#include<time.h>
using namespace std;

void downAdjust(vector<int>& heap, int i)
{
    int n = heap[0];
    while(2*i <= n)
    {
        int j = 2*i;  //left child
        if(j+1 <= n && heap[j] < heap[j+1])  // if right child exists and it's value is greater than left child
        {
            j = j+1;
        }
        if(heap[i] < heap[j])  // if parents value is less than child then swap it and continue the process for downward elemets of that parent
        {
            swap(heap[i], heap[j]);
            i = j;
        }
        else{
            break;
        }
    }
}

void printArray(vector<int> vect)
{
    for(int i = 1; i < vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> heap(n+1);
    srand(time(NULL));
    for(int i = 1; i <= n; i++)
    {
        heap[i] = rand() % 100;
        // cin>>heap[i];
    }
    heap[0] = n;
    // cout<<"\nOriginal Array: ";
    // printArray(heap);
    clock_t start = clock();
    for(int i = n/2; i>= 1; i--)
    {
        downAdjust(heap, i);
    }

    // cout<<"\nMax heap: ";
    // printArray(heap);

    while(heap[0] >= 1)
    {
        int lastInd = heap[0];
        swap(heap[1], heap[lastInd]);
        heap[0]--;
        downAdjust(heap, 1);
    }
    clock_t end = clock();
    // cout<<"\nSorted Array: ";
    // printArray(heap);

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout<<"Time taken for sorting the elements: "<<time_taken<<" seconds"<<endl;
    
    return 0;
}
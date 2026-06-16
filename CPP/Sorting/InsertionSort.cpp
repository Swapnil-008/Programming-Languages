#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

void insertionSort(vector<int>& vect)
{
    for(int i = 1; i < vect.size(); i++)
    {
        int temp = vect[i];
        int j;
        for(j = i-1; j >= 0; j--)
        {
            if(vect[j] > temp)
            {
                vect[j+1] = vect[j];
            }
            else{
                break;
            }
        }
        vect[j+1] = temp;
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
    for(int i = 0; i < 100000 ; i++)
    {
        vect.push_back(rand() % 1000);
    }

    // cout<<"Origingal Array: ";
    // printArray(vect);
    clock_t start = clock();
    insertionSort(vect);
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    // cout<<"Sorted Array: ";
    // printArray(vect);

    cout<<"Time taken for sorting the elements: "<<time_taken<<" seconds"<<endl;
}
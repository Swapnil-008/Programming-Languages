#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

// int partition(vector<int>& vect, int low, int high)
// {
//     int p = low+1;
//     int q = high;
//     int pivot = vect[low];
//     while(true)
//     {
//         while(p <= high && vect[p] <= pivot)
//         {
//             p++;
//         }
//         while(vect[q] > pivot)
//         {
//             q--;
//         }
//         if(p < q)
//         {
//             swap(vect[p], vect[q]);
//         }
//         else{
//             break;
//         }
//     }
//     swap(vect[low], vect[q]);
//     return q;
// }

// void quicksort(vector<int>& vect, int low, int high)
// {
//     if(low < high)
//     {
//         int k = partition(vect, low, high);
//         quicksort(vect, low, k-1);
//         quicksort(vect, k+1, high);
//     }
// }

// void printArray(vector<int> vect)
// {
//     for(int i = 0; i < vect.size(); i++)
//     {
//         cout<<vect[i]<<" ";
//     }
//     cout<<endl;
// }

// int main()
// {
//     vector<int> vect;
//     srand(time(NULL));
//     for(int i = 0; i < 100000; i++)
//     {
//         vect.push_back(rand() % 10000);
//     }

//     // cout<<"Origingal Array: ";
//     // printArray(vect);
//     clock_t start = clock();
//     quicksort(vect, 0, 99999);
//     clock_t end = clock();

//     double time_taken = double(end - start) / CLOCKS_PER_SEC;
//     // cout<<"Sorted Array: ";
//     // printArray(vect);

//     cout<<"Time taken for sorting the elements: "<<time_taken<<" seconds"<<endl;
// }


int partition(vector<int>& nums, int low, int high)
{
    int i = low + 1;
    int j = high;
    int pivot = nums[low];
    while(true)
    {
        while(i <= high && nums[i] <= pivot)
        {
            i++;
        }
        while(nums[j] > pivot)
        {
            j--;
        }
        if(i < j)
        {
            swap(nums[i], nums[j]);
        }
        else{
            break;
        }
    }
    swap(nums[low], nums[j]);
    return j;
}

void quickSort(vector<int>& nums, int low, int high)
{
    if(low < high)
    {
        int ind = partition(nums, low, high);
        quickSort(nums, low, ind - 1);
        quickSort(nums, ind + 1, high);
    }
}
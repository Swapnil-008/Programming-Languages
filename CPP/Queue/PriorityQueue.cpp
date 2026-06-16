#include<bits/stdc++.h>
using namespace std;

// Defining custom min heap

class MyPriorityQueue
{
    private:
    vector<int> heap;
    void heapifyUp(int ind);
    void heapifyDown(int ind);
    public:
    bool empty();
    int top();
    void push(int value);
    void pop();
    int size();
};

bool MyPriorityQueue::empty()
{
    if(heap.size())
    {
        return false;
    }
    return true;
}

int MyPriorityQueue::top()
{
    if(heap.empty())
    {
        throw runtime_error("Heap is empty");
    }
    return heap[0];
}

void MyPriorityQueue::pop()
{
    if(empty())
    {
        throw runtime_error("Heap is empty");
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

int MyPriorityQueue::size()
{
    return heap.size();
}

void MyPriorityQueue::push(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

// Move element up to maintain heap property
void MyPriorityQueue::heapifyUp(int ind)
{
    while(ind > 0)
    {
        int parent = (ind - 1) / 2;
        if(heap[parent] > heap[ind])
        {
            swap(heap[ind], heap[parent]);
            ind = parent;
        }
        else{
            break;
        }
    }
}

// Move element down to maintain heap property
void MyPriorityQueue::heapifyDown(int ind)
{
    int size = heap.size();
    while(true)
    {
        int left = 2 * ind + 1;
        int right = 2* ind + 2;
        int smallest = ind;
        if(left < size && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if(right < size && heap[right] < heap[smallest])
        {
            smallest = right;
        }
        if(smallest != ind)
        {
            swap(heap[ind], heap[smallest]);
            ind = smallest;
        }
        else{
            break;
        }
    }
}
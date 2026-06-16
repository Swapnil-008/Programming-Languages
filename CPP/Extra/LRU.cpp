#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;
    Node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};
class LRUCache
{
    unordered_map<int, pair<int, Node *>> umap;
    Node *head, *tail;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key)
    {
        if (umap.find(key) != umap.end())
        {
            Node *temp = umap[key].second;
            // removing node from the existing position
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            // insert at head
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
            temp->prev = head;
            return umap[key].first;
        }
        return -1;
    }
    void put(int key, int value)
    {
        if (umap.find(key) != umap.end())
        {
            Node *temp = umap[key].second;
            // removing node from the existing position
            umap[key].first = value;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            // adding node on the top
            temp->next = head->next;
            temp->next->prev = temp;
            temp->prev = head;
            head->next = temp;
        }
        else
        {
            if (umap.size() >= capacity)
            {
                umap.erase(tail->prev->data); // removing the Least Recent Used key value
                Node *temp = tail->prev;
                temp->prev->next = tail;
                tail->prev = temp->prev; // adding the new key value pair on top
                temp->data = key;
                umap[key] = {value, temp};
                temp->next = head->next;
                temp->next->prev = temp;
                temp->prev = head;
                head->next = temp;
            }
            else
            {
                Node *newNode = new Node(key);
                umap[key] = {value, newNode};
                newNode->next = head->next;
                newNode->next->prev = newNode;
                newNode->prev = head;
                head->next = newNode;
            }
        }
    }
};
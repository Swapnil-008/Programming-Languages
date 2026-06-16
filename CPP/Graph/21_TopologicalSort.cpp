#include<bits/stdc++.h>
using namespace std;


// Topological sort works only for Directed Acyclic Graph (DAG).
// Linear ordering of vertices such that if there is an edge between U and V, U appears before V in that ordering.

// Directed graph is required because it is impossible to order u before v and v before u if there is an edge between u and v, that's why it has to be Acyclic
// and if a graph contains cycle like (1 -> 2, 2 -> 3, 3 -> 1), then 1 can be placed before 2, 2 also can be placed before 3, but then 3 can't be placed before 1, no any result possible which could satisfy the required order, that's why graph has to be acyclic

// So Topological Sort give ordering of nodes such that every dependency is respected, let's consider there is an edge between U and V, 
// it states that U is a prerequisite of V and U must happen before V
// In DFS-based topological sort, we push nodes to the stack only after visiting all their neighbors. 
// This ensures that dependencies (children) are pushed first, and when we pop from the stack, the parent appears before the child, satisfying the topological order

void dfsRecursiveTopologicalSort(int node, vector<vector<int>>& adjNodes, vector<int>& visited, stack<int>& stack)
{
    visited[node] = 1;
    for(int i = 0; i < adjNodes[node].size(); i++)
    {
        if(!visited[adjNodes[node][i]])
        {
            dfsRecursiveTopologicalSort(adjNodes[node][i], adjNodes, visited, stack);
        }
    }
    // Push the node after visiting all its adjacent nodes (post-order DFS).
    // This ensures all dependent nodes are already in the stack.
    // When popped, it gives a valid topological ordering where
    // parent appears before its children.
    stack.push(node);
}
void topologicalSort(int V, vector<vector<int>>& adjNodes)
{
    vector<int> visited(V, 0);
    stack<int> stack;
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            dfsRecursiveTopologicalSort(i, adjNodes, visited, stack);
        }
    }
    while(!stack.empty())
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }
}
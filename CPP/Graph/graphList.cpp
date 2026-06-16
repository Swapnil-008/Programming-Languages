#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int vertex;
    int data;
    Node* next;
    Node(int vertex, int data)
    {
        this->vertex = vertex;
        this->data = data;
        next = NULL;
    }
};

class Graph
{
    public:
    vector<Node*> head;
    vector<Node*> last;
    int isDirected;
    int isWeighted;
    Graph()
    {
        int n;
        cout<<"Enter No. of vertices: ";
        cin>>n;
        head.resize(n, NULL);
        last.resize(n, NULL);
        cout<<"Enter isDirected (0/1): ";
        cin>>isDirected;
        cout<<"Enter isWeighted (0/1): ";
        cin>>isWeighted;
    }
    void readGraphList();
    void insertEdge(int u, int v, int w);
    void showGraphLists();
    vector<int> inDegree();
    vector<int> outDegree();
    vector<int> BFS();
    void DFS();
    void dfsRecursive(int end, vector<int>& visited);
    void connectedComponents();
    void traversalBFS(int start, vector<int>& visited);
};

void Graph::readGraphList()
{
    int n = head.size();
    int u, v, w;
    while(true)
    {
        cout<<"Enter Edge (start, end, and weight): ";
        cin>>u>>v>>w;
        if(u == -1 || v == -1)
        {
            break;
        }
        if(!isWeighted)
        {
            w = (w >= 1) ? 1 : 0;
        }
        insertEdge(u, v, w);
        if(!isDirected)
        {
            insertEdge(v, u, w);
        }
    }
}

void Graph::insertEdge(int u, int v, int w)
{
    if(head[u] == NULL)
    {
        head[u] = new Node(v, w);
        last[u] = head[u];
    }
    else{
        last[u]->next = new Node(v, w);
        last[u] = last[u]->next;
    }
}

void Graph::showGraphLists()
{
    int n = head.size();
    for(int i = 0; i < n; i++)
    {
        cout<<"Vertex "<<i<<": ";
        Node* ptr = head[i];
        while(ptr != NULL)
        {
            cout<<"[ "<<ptr->vertex<<", "<<ptr->data<<" ]"<<", ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
}

vector<int> Graph::inDegree()
{
    int n = head.size();
    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++)
    {
        Node* ptr = head[i];
        while(ptr != NULL)
        {
            indegree[ptr->vertex]++;
            ptr = ptr->next;
        }
    }
    return indegree;
}

vector<int> Graph::outDegree()
{
    int n = head.size();
    vector<int> outdegree(n, 0);
    for(int i = 0; i < n; i++)
    {
        Node* ptr = head[i];
        while(ptr != NULL)
        {
            outdegree[i]++;
            ptr = ptr->next;
        }
    }
    return outdegree;
}

void Graph::connectedComponents()
{
    int components = 0;
    int n = head.size();
    vector<int>visited(n, 0);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            traversalBFS(i, visited);
            components++;
        }
    }
    cout<<"\nNo. of Components: "<<components<<endl;
}

void Graph::traversalBFS(int start, vector<int>& visited)
{
    queue<int> queue;
    queue.push(start);
    visited[start] = 1;
    while(!queue.empty())
    {
        int u = queue.front();
        queue.pop();
        Node* ptr = head[u];
        while(ptr != NULL)
        {
            int v = ptr->vertex;
            if(!visited[v])
            {
                visited[v] = 1;
                queue.push(v);
            }
            ptr = ptr->next;
        }
    }
}

vector<int> Graph::BFS()
{
    int n = head.size();
    vector<int> result;
    vector<int> visited(n);
    queue<int> queue;
    queue.push(0);
    visited[0] = 1;
    while(!queue.empty())
    {
        int start = queue.front();
        queue.pop();
        result.push_back(start);
        Node* ptr = head[start];
        while(ptr != NULL)
        {
            int end = ptr->vertex;
            if(!visited[end])
            {
                visited[end] = 1;
                queue.push(end);
            }
            ptr = ptr->next;
        }
    }
    return result;
}

void Graph::dfsRecursive(int end, vector<int>& visited)
{
    visited[end] = 1;
    cout<<end<<" ";
    Node* ptr = head[end];
    while(ptr != NULL)
    {
        if(!visited[ptr->vertex])
        {
            dfsRecursive(ptr->vertex, visited);
        }
        ptr = ptr->next;
    }
}

void Graph::DFS()
{
    int n = head.size();
    vector<int> visited(n);
    cout<<"DFS: ";
    dfsRecursive(0, visited);
}



int main()
{
    Graph gph;
    gph.readGraphList();
    // gph.showGraphLists();

    // auto indegree = gph.inDegree();
    // auto outdegree = gph.outDegree();

    // cout<<"\nIndegree:  ";
    // for(int i = 0; i < indegree.size(); i++)
    // {
    //     cout<<indegree[i]<<", ";
    // }

    // cout<<"\nOutdegree: ";
    // for(int i = 0; i < outdegree.size(); i++)
    // {
    //     cout<<outdegree[i]<<", ";
    // }

    // auto bfs = gph.BFS();
    // cout<<"\nBFS: ";
    // for(int num : bfs)
    // {
    //     cout<<num<<" ";
    // }

    // gph.connectedComponents();

    auto vect = gph.BFS();
    for(int num : vect)
    {
        cout<<num<<" ";
    }
    return 0;
}


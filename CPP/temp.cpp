#include <bits/stdc++.h>
using namespace std;

// // class Number
// // {
// //     public:
// //     int x;
// //     static int y;
// //     static Number show()
// //     {
// //         // cout<<x<<endl; -->error Non-static data members are not directly accessible inside static member function
// //         cout<<y<<endl;
// //         cout<<"In show"<<endl;
// //         Number Temp;
// //         Temp.x = 10;
// //         // Number::y = 10;  // Alternative
// //         return Temp;
// //     }
// //     void print()
// //     {
// //         x = 5;
// //     }
// // };
// // int Number::y = 25;
// // int main()
// // {
// //     Number N1, N2;
// //     N1 = Number::show();
// //     // N1.print();
// //     cout<<N1.x<<" "<<N2.x<<endl;
// //     return 0;
// // }

// // class Number;
// // class Digit
// // {
// //     void print(Number Temp);
// //     public:
// // };
// // class Number
// // {
// //     private:
// //     int x;
// //     // friend void Digit::print(Number Temp);  // As this method is not accessible outside the class we can make it friend, that's why we have to make the class friend
// //     friend class Digit;
// // };
// // void Digit::print(Number Temp)
// // {
// //     cout<<"Enter x: ";
// //     cin>>Temp.x;
// // }
// // int main()
// // {
// //     int *p = new int[1];  // int *p = new int(20);
// //     *p = 20;
// //     cout<<*p;

// //     return 0;
// // }

// // class Number
// // {
// //     public:
// //     int *ptr;
// //     Number()
// //     {
// //         ptr = new int(10);
// //         cout<<"In Default Constructor"<<endl;
// //     }
// //     Number(Number &Temp)
// //     {
// //         ptr = Temp.ptr;
// //         cout<<"In Copy Constructor"<<endl;
// //     }
// //     void show()
// //     {
// //         cout<<(long long)ptr<<" "<<*ptr<<endl;
// //     }
// // };

// // int main()
// // {
// //     Number N1;
// //     Number N2 = N1;
// //     N1.show();
// //     N2.show();

// //     return 0;
// // }

// class Parent1
// {
// public:
//     Parent1()
//     {
//         cout << "In parent1 constructor" << endl;
//     }
//     void show()
//     {
//         cout << "In Parent1 show()" << endl;
//     }
// };

// class Parent2
// {
// public:
//     Parent2()
//     {
//         cout << "In parent2 constructor" << endl;
//     }
//     void show()
//     {
//         cout << "In Parent2 show()" << endl;
//     }
// };

// class Child : public Parent1, public virtual Parent2
// {
// public:
//     void show()
//     {
//         cout << "In Child show()" << endl;
//     }
// };

// int main()
// {
//     Child child;
//     // child.show();
//     // child.Parent1::show();
//     // child.Parent2::show();

//     cout << 'x' - 'b';
//     return 0;
// }

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        int n = mat.size();
        int k = 0;
        while(k < 4)
        {
            for(int i = 0; i < n / 2; i++)
            {
                swap(mat[i], mat[n - i - 1]);
            }
            for(int i = 0; i < n; i++)
            {
                for(int j = i; j < n; j++)
                {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            if(mat == target)
            {
                return true;
            }
            k++;
        }
        return false;
    }
};

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k)
    {

    }
};

class Solution {
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> result;
        dfsRecursive(0, adj, visited, result);
        return result;
    }
    void dfsRecursive(int u, vector<int> adjNodes[], vector<int>& visited, vector<int>& result)
    {
        visited[u] = 1;
        result.push_back(u);
        for(int v: adjNodes[u])
        {
            if(!visited[v])
            {
                dfsRecursive(v, adjNodes, visited, result);
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> result;
        queue<int> queue;
        queue.push(0);
        visited[0] = 1;
        while(!queue.empty())
        {
            int u = queue.front();
            result.push_back(u);
            queue.pop();
            for(int v: adj[u])
            {
                if(!visited[v])
                {
                    queue.push(v);
                    visited[v] = 1;
                }
            }
        }
        return result;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        vector<vector<int>> adjList(V);
        for(int i = 0; i < V; i++)
        {
            for(int  j = 0; j < V; j++)
            {
                if(adj[i][j] != 0 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> visited(V);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                count++;
                bfs(adjList, i, V, visited);
            }
        }
        return count;
    }
    void bfs(vector<vector<int>> adj, int source, int V, vector<int>& visited)
    {
        queue<int> queue;
        queue.push(source);
        visited[source] = 1;
        while(!queue.empty())
        {
            int u = queue.front();
            queue.pop();
            for(int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i];
                if(!visited[v])
                {
                    visited[v] = 1;
                    queue.push(v);
                }
            }
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != '0' && !visited[i][j])
                {
                    bfs(i, j, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }

    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            // Traversing the 4 possible neighbors (up, down, left, right)
            for (int dr = -1; dr <= 1; dr++)
            {
                for (int dc = -1; dc <= 1; dc++)
                {
                    if (abs(dr) + abs(dc) != 1)
                    {
                        continue;
                    }
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != '0' && !visited[nr][nc])
                    {
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
};

class Solution {
  public:
    void dfs(int row, int col, int iniColor, int newColor, vector<vector<int>>& result, vector<vector<int>>& image)
    {
        int m = result.size();
        int n = result[0].size();
        result[row][col] = newColor;
        for(int dr = -1; dr <= 1; dr++)
        {
            for(int dc = -1; dc <= 1; dc++)
            {
                if(abs(dr) + abs(dc) != 1)
                {
                    continue;
                }
                int nr = row + dr;
                int nc = col + dc;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == iniColor && result[nr][nc] != newColor)
                {
                    dfs(nr, nc, iniColor, newColor, result, image);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        // code here
        vector<vector<int>> result = image;
        int iniColor = result[sr][sc];
        dfs(sr, sc, iniColor, newColor, result, image);
        return result;
    }
};
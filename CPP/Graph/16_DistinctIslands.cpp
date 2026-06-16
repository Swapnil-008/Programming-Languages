#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int m, n;
    set<vector<pair<int, int>>> st;
    int countDistinctIslands(vector<vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> temp;
                    dfs(i, j, i, j, temp, grid, visited);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }

    void dfs(int row, int col, int baseRow, int baseCol, vector<pair<int, int>>& temp, vector<vector<int>>& grid, vector<vector<int>>& visited)
    {
        if(row < 0 || col < 0 || row >= m || col >= n || visited[row][col] || grid[row][col] == 0)
        {
            return;
        }
        visited[row][col] = 1;
        temp.push_back({row - baseRow, col - baseCol});
        for(int dr = -1; dr <= 1; dr++)
        {
            for(int dc = -1; dc <= 1; dc++)
            {
                if(abs(dr) + abs(dc) != 1)
                {
                    continue;
                }
                dfs(row + dr, col + dc, baseRow, baseCol, temp, grid, visited);
            }
        }
    }
};

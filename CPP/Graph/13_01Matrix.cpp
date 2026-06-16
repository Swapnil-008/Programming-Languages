#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> queue;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    queue.push({i, {j, 0}});
                    visited[i][j] = 1;
                }
            }
        }
        while(!queue.empty())
        {
            int row = queue.front().first;
            int col = queue.front().second.first;
            int dist = queue.front().second.second;
            mat[row][col] = dist;
            queue.pop();
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
                    if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                    {
                        continue;
                    }
                    if(visited[nr][nc] == 0 && mat[nr][nc] == 1)
                    {
                        visited[nr][nc] = 1;
                        queue.push({nr, {nc, dist + 1}});
                    }
                }
            }
        }
        return mat;
    }
};
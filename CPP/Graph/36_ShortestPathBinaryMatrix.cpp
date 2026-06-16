#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        // Edges are already in sorted manner, so there is no need to min heap, we can go with simple queue
        queue<pair<int, pair<int, int>>> queue; // distance, row, col
        if(grid[0][0] == 0)
        {
            queue.push({0, {0, 0}});
            distance[0][0] = 0;
        }
        while(!queue.empty())
        {
            int dist = queue.front().first;
            int row = queue.front().second.first;
            int col = queue.front().second.second;
            queue.pop();
            for(int dr = -1; dr <= 1; dr++)
            {
                for(int dc = -1; dc <= 1; dc++)
                {
                    if(dc == 0 && dr == 0)
                    {
                        continue;
                    }
                    int nr = row + dr;
                    int nc = col + dc;
                    if(nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] != 0)
                    {
                        continue;
                    }
                    if(dist + 1 < distance[nr][nc])
                    {
                        distance[nr][nc] = dist + 1;
                        queue.push({distance[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        // We have added 1 in final answer because we have counted no.of edges and in ans no. of vertices are expected
        return distance[n - 1][n - 1] == INT_MAX ? -1 : distance[n - 1][n - 1] + 1;
    }
};
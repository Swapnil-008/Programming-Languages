#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        distance[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pqueue; // absolute distance of a path, row, col
        pqueue.push({0, {0, 0}});
        while(!pqueue.empty())
        {
            int dist = pqueue.top().first;
            int row = pqueue.top().second.first;
            int col = pqueue.top().second.second;
            pqueue.pop();
            if(row == m - 1 && col == n - 1)
            {
                return dist;
            }
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
                    int absDiff = abs(heights[row][col] - heights[nr][nc]);
                    int newEffort = max(absDiff, dist);
                    if(newEffort < distance[nr][nc])
                    {
                        distance[nr][nc] = newEffort;
                        pqueue.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};
#include<bits/stdc++.h>
using namespace std;

// 'O's connected to any border can't get convert into X, so converting those into '#' and converting remaining 'O's to 'X' and then reverting '#'s to 'O'

class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
            {
                dfs(i, 0, board);
            }
            if(board[i][n - 1] == 'O')
            {
                dfs(i, n - 1, board);
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(board[0][i] == 'O')
            {
                dfs(0, i, board);
            }
            if(board[m - 1][i] == 'O')
            {
                dfs(m - 1, i, board);
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(int row, int col, vector<vector<char>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        if(row < 0 || col < 0 || row >= m || col >= n || board[row][col] != 'O')
        {
            return;
        }
        board[row][col] = '#';
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
                if(board[nr][nc] == 'O')
                {
                    dfs(nr, nc, board);
                }
            }
        }
    }
};

int main()
{
    set<vector<vector<int>>> set;
    set.insert({{1, 2, 3, 4}, {5, 6, 7, 8}});
    set.insert({{1, 2, 3, 4}, {5, 6, 7, 8}});
    set.insert({{1, 2, 3, 4}, {5, 9, 7, 8}});

    for(auto temp: set)
    {
        for(int i = 0; i < temp.size(); i++)
        {
            for(int j = 0; j < temp[i].size(); j++)
            {
                cout<<temp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
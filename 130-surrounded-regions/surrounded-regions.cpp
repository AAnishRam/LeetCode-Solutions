class Solution {
public:

    void bfs(vector<vector<char>>& board, vector<vector<int>> &visited, int r, int c)
    {
        int n = board.size();
        int m = board[0].size();
        bool isAtEdge = false;
        queue<pair<int, int>> q;
        queue<pair<int, int>> temp;

        q.push({r, c});
        temp.push({r, c});
        visited[r][c] = 1;
        if(r == 0 || r == n-1 || c == 0 || c == m-1)
            isAtEdge = true;

        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
                && !visited[newRow][newCol] && board[newRow][newCol] == 'O')
                {
                    q.push({newRow, newCol});
                    temp.push({newRow, newCol});
                    visited[newRow][newCol] = 1;

                    if(newRow == 0 || newRow == n-1 || newCol == 0 || newCol == m-1)
                        isAtEdge = true;

                }
            }
        }


        if(!isAtEdge)
        {
            while(!temp.empty())
            {
                int row = temp.front().first;
                int col = temp.front().second;
                temp.pop();
                board[row][col] = 'X';
            }
        }
    }


    // there is a another method also lets we do bfs of all o's which are only at boundaries
    // and mark the bfs nodes as visited it states that all the regions formed over the bfs
    // of that boundary o's cant be converted so keep those in track in the visited array
    // and do other things

    void newBfs(vector<vector<char>>& board, vector<vector<int>> &visited, int r, int c)
    {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;

        q.push({r, c});
        visited[r][c] = 1;
        

        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
                && !visited[newRow][newCol] && board[newRow][newCol] == 'O')
                {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = 1;
                }
            }
        }

    }

    

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //     {
        //         if (board[i][j] == 'O' && !visited[i][j])
        //             bfs(board, visited, i, j);
        //     }
        // }

        // top & bottom boundry
        for(int i = 0; i < m; i++)
        {
            if(board[0][i] == 'O' && !visited[0][i])
                newBfs(board, visited, 0, i);

            if(board[n-1][i] == 'O' && !visited[n-1][i])
                newBfs(board, visited, n-1, i);
        }

        //left and right boundary
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O' && !visited[i][0])
                newBfs(board, visited, i, 0);

            if(board[i][m-1] == 'O' && !visited[i][m-1])
                newBfs(board, visited, i, m-1);

        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }

        //left boundary


    }
};
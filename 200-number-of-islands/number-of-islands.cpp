class Solution {
public:
    void BFS(int row,int col,vector<vector<char>>grid,vector<vector<bool>>&visited){
        visited[row][col] = true;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();
    
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = curr_row + dx[i];
            int ncol = curr_col + dy[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == '1' &&
                !visited[nrow][ncol]) {
                visited[nrow][ncol] = true;
                q.push({nrow, ncol});
            }
        }
    }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    count++;
                    BFS(row,col,grid,visited);
                }
            }
        }
        return count;
    }
};
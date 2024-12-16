class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<vector<int>> directions){
        visited[row][col] = 1;

        int m = grid.size();
        int n = grid[0].size();

        for(auto dir : directions){
            int nrow = row + dir[0];
            int ncol = col + dir[1];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, visited, grid, directions);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        vector<vector<int>> directions = {{0,1}, {-1,0}, {0,-1}, {1,0}};

        //make call for dfs for first and last row(boundaries)
        for(int i=0; i<n; i++){
            //for first row
            if(!visited[0][i] && grid[0][i] == 1){
                dfs(0, i, visited, grid, directions);
            }
            //for last row
            if(!visited[m-1][i] && grid[m-1][i] == 1){
                dfs(m-1, i, visited, grid, directions);
            }
        }

        //make call for first and last column
        for(int i=0; i<m; i++){
            //for first column
            if(!visited[i][0] && grid[i][0] == 1){
                dfs(i, 0, visited, grid, directions);
            }
            //for last row
            if(!visited[i][n-1] && grid[i][n-1] == 1){
                dfs(i, n-1, visited, grid, directions);
            }
        }

        int finalOne = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]) finalOne++;
            }
        }

        return finalOne;
    }
};
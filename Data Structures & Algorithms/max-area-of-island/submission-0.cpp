class Solution {
public:
int maxarea = 0;
int area = 0;

    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        area++;
        maxarea = max(maxarea, area);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);

    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    area = 0;
                    dfs(grid, i, j);
                }
            }
        }
        return maxarea;
    }
};
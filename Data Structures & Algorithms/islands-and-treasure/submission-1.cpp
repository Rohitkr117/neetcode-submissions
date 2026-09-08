class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                    q.push({i,j});
            }
        }
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            count++;
            while(size--){
                auto[i,j] = q.front();
                q.pop();
                if(i < m - 1 && grid[i+1][j] == 2147483647){
                    grid[i+1][j] = count;
                    q.push({i+1,j});
                }
                if(i > 0 && grid[i-1][j] == 2147483647){
                    grid[i-1][j] = count;
                    q.push({i-1,j});
                }
                if(j < n - 1 && grid[i][j+1] == 2147483647){
                    grid[i][j+1] = count;
                    q.push({i,j+1});
                }
                if(j > 0 && grid[i][j-1] == 2147483647){
                    grid[i][j-1] = count;
                    q.push({i,j-1});
                }
            }
        }
    }
};

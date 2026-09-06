class Solution {
public:
queue<pair<int, int>> q;
int count = 0;
int min = 0;
int newmin = 0;
bool rot = false;
    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q){
        while(!q.empty()){
            int i= q.front().first;
            int j= q.front().second;
            q.pop();
            min--;
            if(i < grid.size() - 1 && grid[i + 1][j] == 1){
                rot = true;
                grid[i+1][j] = 2;
                q.push({i+1, j});
                newmin++;
            }
            if(i > 0 && grid[i - 1][j] == 1){
                rot = true;
                grid[i-1][j] = 2;
                q.push({i-1, j});
                newmin++;
            }
            if(j < grid[0].size() - 1 && grid[i][j+1] == 1){
                rot = true;
                grid[i][j+1] = 2;
                q.push({i, j+1});
                newmin++;
            }
            if(j > 0 && grid[i][j-1] == 1){
                rot = true;
                grid[i][j-1] = 2;
                q.push({i, j-1});
                newmin++;
            }
            if(rot && min == 0){
                rot = false;
                count++;
                min = newmin;
                newmin = 0;
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {

       for(int i = 0; i < grid.size(); i++){
            for(int j = 0;  j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    min++;
                }
            }
       }
       bfs(grid, q);
       for(int i = 0; i < grid.size(); i++){
            for(int j = 0;  j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
       }
       return count;
    }
};

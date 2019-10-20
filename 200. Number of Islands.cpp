//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int numIslands (vector <vector <char> >& grid) {
        if (grid.empty() || grid[0].empty()){
            return 0;
        }
        
        int cnt = 0;
        int m = (int) grid.size();
        int n = (int) grid[0].size();
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                cnt += dfs(grid, m, n, i, j);
            }
        }
        return cnt;
    }
private:
    int dfs (vector <vector <char> >& grid, int m, int n, int i, int j){
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return 0;
        grid[i][j]='0';
        dfs(grid, m, n, i-1, j);
        dfs(grid, m, n, i,   j-1);
        dfs(grid, m, n, i+1, j); 
        dfs(grid, m, n, i,   j+1);
        return 1;
    }
};

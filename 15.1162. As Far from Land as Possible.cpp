//https://leetcode.com/problems/as-far-from-land-as-possible/
class Solution {
public:

    bool Check(vector<vector<int>> gr, int a){
        bool fl = false;
        int i=0;
        while (!(fl) && i<gr.size()){
            int j = 0;
            while (!(fl) && j<gr[0].size()){
                if (gr[i][j] != a) fl = true;
                else j++;
            }
            i++;
        }
        return fl;
    }

int maxDistance(vector<vector<int>> & grid) {
    if (Check(grid, grid[0][0]) == false) return -1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

int n = grid.size();
vector<vector<int>> x(n, vector<int>(n, INT_MAX));

queue<pair<int,int>> q;

for(int i = 0; i<n; i++)
    for(int j = 0; j<n; j++)
        if (grid[i][j] == 1) {
            q.push({i,j});
            x[i][j] = 0;
        }

while (!q.empty()){
    auto p = q.front();
    q.pop();
    
    for(int i = 0; i<4; i++){
        int y = p.first + dx[i];
        int z = p.second + dy[i];

        if (y>=0 && z>=0 && y<n && z<n && grid[y][z]!=1){
            int dist = 1 + x[p.first][p.second];
            if (x[y][z] > dist){
                x[y][z] = dist;
                q.push({y,z});
            }
        }
    }
}

int d = 0;

for (int i = 0; i<n; i++)
    for (int j = 0; j<n; j++){
        if (grid[i][j]==0&&x[i][j]!=INT_MAX) d = max(d, x[i][j]);
}

return d;


}
};

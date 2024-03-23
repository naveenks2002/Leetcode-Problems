class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int fresh = 0;
        int vis[n][m];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else
                    vis[i][j] = 0;

                if(grid[i][j]==1)
                    fresh++;
            }
        }   
        int drow[4] = {-1,0,+1,0};
        int dcol[4] = {0,+1,0,-1};
        int t = 0;
        int cnt=0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            q.pop();
            t = max(t,time);
            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        if(cnt!=fresh)
            return -1;

        return t;
    }
};
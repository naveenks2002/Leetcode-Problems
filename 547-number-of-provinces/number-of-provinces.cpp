class Solution {
public:
    void dfs(int node, vector<int> adj[],vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it])
                dfs(it,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> adj[v];

        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int> vis;
        for(int i=0;i<v;i++) 
        {
            vis.push_back(0);
        } 
        for(int i=0; i<v; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};
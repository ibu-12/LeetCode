class Solution {
public:
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size(), ans = 0;
        vector<int> vis(n, 0); 
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans++;
                queue<int> q;
                q.push(i);
                vis[i] = 1;  
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int j = 0; j < n; j++){
                        if(v[node][j] == 1 && !vis[j]){
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
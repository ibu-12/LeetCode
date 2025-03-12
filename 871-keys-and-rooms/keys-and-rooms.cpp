class Solution {
public:

    int c=1;
    void dfs(vector<vector<int>>& rooms,vector<bool>& vis,int index){
        for(int j=0;j<rooms[index].size();j++){
            int i=rooms[index][j];
            if(!vis[i]){
                vis[i]=true;
                c++;
                dfs(rooms,vis,i);
            }
        }
    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        vis[0]=true;
        dfs(rooms,vis,0);
        return c==n;
    }
};
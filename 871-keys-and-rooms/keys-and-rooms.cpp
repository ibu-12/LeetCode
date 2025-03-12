class Solution {
public:

    void dfs(vector<vector<int>>& rooms,vector<bool>& vis,int index,int &c){
        for(int j=0;j<rooms[index].size();j++){
            int i=rooms[index][j];
            if(!vis[i]){
                vis[i]=true;
                c++;
                dfs(rooms,vis,i,c);
            }
        }
    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        vis[0]=true;
        int c=1;
        dfs(rooms,vis,0,c);
        return c==n;
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int m=a.size();
        int n=a[0].size();
        int u,l;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    dp[i][j]=a[i][j];
                else{
                    u=a[i][j];
                    l=a[i][j];
                    if(i>0)
                        u+=dp[i-1][j];
                    else 
                        u+=1e9;
                    if(j>0)
                        l+=dp[i][j-1];
                    else 
                        l+=1e9;
                    dp[i][j]=min(u,l);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
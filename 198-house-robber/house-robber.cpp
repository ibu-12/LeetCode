class Solution {
public:

    long long f(vector<int>& arr,vector<int>& dp){
        
        if(arr[0]>0)dp[0]=arr[0];
        int n=arr.size();
        for(int i=1;i<arr.size();i++){
            long long p=arr[i];
            if(i>1){
                p+=dp[i-2];
            }
            long long np=dp[i-1];
            dp[i]=max(p,np);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        return f(nums,dp);
    }
};
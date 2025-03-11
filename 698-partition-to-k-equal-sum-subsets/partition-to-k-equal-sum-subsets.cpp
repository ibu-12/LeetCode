class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),sum);
        if(nums.size()<k || sum%k)return false;

        vector<int>vis(nums.size(),false);
        return gen(nums,vis,sum/k,0,0,k);
    }
    bool gen(vector<int>& nums,vector<int>& vis,int tar,int cs,int i,int k){
        if(k==1){
            return true;
        }
        if(cs==tar){
            return gen(nums,vis,tar,0,0,k-1);
        }
        for(int j=i;j<nums.size();j++){
            if(vis[j] || cs+nums[j]>tar)continue;
            vis[j]=true;
            if (gen(nums,vis,tar,cs+nums[j],j+1,k)) return true;
            vis[j]=false;
        }
        return false;
    }
};
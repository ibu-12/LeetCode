class Solution {
public:

    void f(int ind ,vector<int>& nums,vector<vector<int>>& ans,int n,vector<int>&ds){
        
        ans.push_back(ds);
        for(int i=ind;i<n;i++){
            ds.push_back(nums[i]);
            f(i+1,nums,ans,n,ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int>ds;
        f(0,nums,ans,n,ds);
        return ans;
    }
};
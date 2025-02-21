class Solution {
public:

    void f(int ind ,vector<int>& nums,vector<vector<int>>& ans,int n,vector<int>&ds){
        if(ind==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        f(ind+1,nums,ans,n,ds);
        ds.pop_back();
        f(ind+1,nums,ans,n,ds);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        // ans.push_back(vector<int>());
        vector<int>ds;
        f(0,nums,ans,n,ds);
        return ans;
    }
};
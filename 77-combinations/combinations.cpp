class Solution {
public:

    void f(int ind ,vector<int>& nums,vector<vector<int>>& ans,int n,vector<int>&ds){
        if(ind==nums.size()){
            if(ds.size()==n)
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        f(ind+1,nums,ans,n,ds);
        ds.pop_back();
        f(ind+1,nums,ans,n,ds);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int>ds;
        f(0,arr,ans,k,ds);
        return ans;
    }
};
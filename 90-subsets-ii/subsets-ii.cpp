class Solution {
public:

    void f(int ind ,vector<int>& arr,vector<vector<int>>& ans,int n,vector<int>&ds){
            
        ans.push_back(ds);
    
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            ds.push_back(arr[i]);
            f(i + 1, arr, ans,n , ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ds;
        f(0,nums,ans,n,ds);
        return ans;
    }
};
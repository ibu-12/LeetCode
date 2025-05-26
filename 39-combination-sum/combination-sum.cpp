class Solution {
public:

    void f(int ind,int tar,vector<int>& arr,vector<int>& ds,vector<vector<int>>&ans){
        if(ind==arr.size()){
            if(tar==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind]<=tar){
            ds.push_back(arr[ind]);
            f(ind,tar-arr[ind],arr,ds,ans);
            ds.pop_back();
        }
        f(ind+1,tar,arr,ds,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,target,arr,ds,ans);
        return ans;
    }
};
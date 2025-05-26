class Solution {
public:

    void f(int ind,vector<int>&ds,vector<int>& arr,vector<vector<int>>&ans,int n){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(arr[ind]);
        f(ind+1,ds,arr,ans,n);
        ds.pop_back();
        f(ind+1,ds,arr,ans,n);
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=arr.size();
        f(0,ds,arr,ans,n);
        return ans;
    }
};
class Solution {

private:

    bool f(vector<int>& nums, int start, int end) {
        for (int i = start; i < end; i++) {
            if (nums[i] == nums[end]) return true;
        }
        return false;
    }

    void f(int ind,vector<int>& nums,vector<vector<int>>&ans){

        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(f(nums,ind,i))continue;
            swap(nums[ind],nums[i]);
            f(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        // sort(nums.begin(),nums.end());
        f(0,nums,ans);
        return ans;
    }
};
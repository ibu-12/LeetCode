class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        do{
            st.insert(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        for(auto  it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
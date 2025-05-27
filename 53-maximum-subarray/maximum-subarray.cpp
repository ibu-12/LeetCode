class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int t=0;
        for(int n:nums){
            if(t<0){
                t=0;
            }
            t+=n;
            res=max(res,t);
        }
        return res;
    }
};